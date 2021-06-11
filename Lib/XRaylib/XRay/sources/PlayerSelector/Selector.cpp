/*
** EPITECH PROJECT, 2020
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** PlayerSelector.cpp
*/

#include "PlayerSelector/Selector.hpp"

void preloadBasicsCharacters(std::vector<PlayerSelector::CharDictionary> &res)
{
    res.push_back({
        "resources/players/3D/Bombermans/white_tpose.glb",
        "resources/players/3D/Bombermans/texture.png",
        0.6,
        "Red",
        Raylib::Color::Red(),
        {
            "resources/players/3D/Bombermans/animations/white_emote.glb", 
            "resources/players/3D/Bombermans/animations/white_walking.glb",
            "resources/players/3D/Bombermans/animations/white_bomb.glb"
        }
    });
    
    res.push_back({
        "resources/players/3D/Bombermans/white_tpose.glb",
        "resources/players/3D/Bombermans/texture.png",
        0.6,
        "Blue",
        Raylib::Color::Blue(),
        {
            "resources/players/3D/Bombermans/animations/white_emote.glb", 
            "resources/players/3D/Bombermans/animations/white_walking.glb",
            "resources/players/3D/Bombermans/animations/white_bomb.glb"
        }
    });
    
    res.push_back({
        "resources/players/3D/Bombermans/white_tpose.glb",
        "resources/players/3D/Bombermans/texture.png",
        0.6,
        "Yellow",
        Raylib::Color::Yellow(),
        {
            "resources/players/3D/Bombermans/animations/white_emote.glb", 
            "resources/players/3D/Bombermans/animations/white_walking.glb",
            "resources/players/3D/Bombermans/animations/white_bomb.glb"
        }
    });

    res.push_back({
        "resources/players/3D/Bombermans/white_tpose.glb",
        "resources/players/3D/Bombermans/texture.png",
        0.6,
        "Green",
        Raylib::Color::Green(),
        {
            "resources/players/3D/Bombermans/animations/white_emote.glb", 
            "resources/players/3D/Bombermans/animations/white_walking.glb",
            "resources/players/3D/Bombermans/animations/white_bomb.glb"
        }
    });
}

std::vector<PlayerSelector::CharDictionary> findCharactersAvailable(int &nb_Characters)
{
    std::vector<PlayerSelector::CharDictionary> res;
    std::string obj;
    std::string texture;
    std::string name;
    float scalable;

    preloadBasicsCharacters(res);

    for (const auto & file : std::filesystem::directory_iterator("resources/players/3D"))
    {
        obj = "null";
        texture = "null";
        scalable = 0.6;
        name = "null";

        if (file.is_directory())
        {
            name = file.path().filename().string();
            for (const auto &f : std::filesystem::directory_iterator(file.path()))
            {
                if (f.path().extension() == ".obj")
                {
                    obj = f.path().string();
                    break;
                }
            }
            for (const auto &f : std::filesystem::directory_iterator(file.path()))
            {
                if (f.path().filename() == "texture.png")
                {
                    texture = f.path().string();
                    break;
                }
            }
            for (const auto &f : std::filesystem::directory_iterator(file.path()))
            {
                if (f.path().filename() == ".scalable")
                {
                    std::ifstream(f.path().string()) >> scalable;

                    std::cout << "################ ||||| Scalable trouve !!! : " << scalable << std::endl;
                }
            }
            if (obj != "null" && texture != "null")
                res.push_back({obj, texture, scalable, name});
        }
    }
    nb_Characters = res.size();
    return res;
}

PlayerSelector::Selector::Selector()
: camera(nullptr), _rotationAxis(0), _players({}), _nbCharacters(0), _charaDictionary(findCharactersAvailable(_nbCharacters)), _map(nullptr)
{
    POS.push_back(POS_1);
    POS.push_back(POS_2);
    POS.push_back(POS_3);
    POS.push_back(POS_4);

    std::cout  << std::endl << "####### Start Player Selector #######"  << std::endl << std::endl;
}

PlayerSelector::Selector::~Selector()
{
    if (camera != nullptr)
        delete camera;
}

PlayerSelector::Player &PlayerSelector::Selector::operator[](const int &index)
{
    return _players[index];
}


const PlayerSelector::Player &PlayerSelector::Selector::operator[](const int &index) const
{
    return _players[index];
}

void PlayerSelector::Selector::firstLoad()
{
    if (_players.size() == 0)
        load();
}

void PlayerSelector::Selector::load()
{
    std::cout << std::endl << "######## Load Player Selector ########" << std::endl << std::endl;

    if (_players.size() == 4)
        return;
    if (!camera)
    {
        Raylib::Vector3 pos(0, 0, 10);
        Raylib::Vector3 target(0, 0, 0);
        Raylib::Vector3 up(0, 1, 0);

        camera = new Raylib::Camera3D(pos, target, up, 30);
        std::cout << "Camera OK" << std::endl;

        camera->updateCamera();

        camera->setCameraMode(CAMERA_FREE);
    }

    std::cout << std::endl << "######## Init Player Selector ########" << std::endl << std::endl;

    _players.push_back(Player(_charaDictionary[0].obj, _charaDictionary[0].texture, _charaDictionary[0].scalable, 0, _charaDictionary[0].name, _charaDictionary[0].color, _charaDictionary[0].animations));
}

std::vector<std::pair<Model, float>> PlayerSelector::Selector::getModels() const
{
    std::vector<std::pair<Model, float>> persos;

    for (auto &p : _players)
    {
        persos.push_back(p.getModel());
    }
    return persos;
}

std::vector<Texture2D> PlayerSelector::Selector::getBlocTextures() const
{
    return _map->getTextures();
}

void PlayerSelector::Selector::unload(const int &id)
{
    std::cout << std::endl << "######## End Player Selector ########" << std::endl << std::endl;

    _players.erase(_players.begin() + id);
}

void PlayerSelector::Selector::unloadAll()
{
    for (PlayerSelector::Player &player : _players)
    {
        _players.pop_back();
    }

    if (camera != nullptr)
        delete camera;
}

void PlayerSelector::Selector::updateRotationAxis()
{
    _rotationAxis += 0.24;

    if (_rotationAxis > 360)
        _rotationAxis -= 360;
}

void PlayerSelector::Selector::drawPlayers()
{
    char i = 0;

    camera->beginMode3D();

    for (PlayerSelector::Player &player : _players)
    {
        player.draw(_rotationAxis, POS[i]);
        i++;
    }

    updateRotationAxis();
    camera->endMode3D();
}

void PlayerSelector::Selector::initMaps(std::vector<std::string> asciiMap)
{
    camera->setPosition({-0.02, -3, 6});
    if (asciiMap.size() != _asciiMap.size()) {
        _map = new Map(_players, asciiMap);
        _asciiMap = asciiMap;
    }
}

void PlayerSelector::Selector::drawMaps()
{
    camera->beginMode3D();

    _map->draw();

    camera->endMode3D();
}

std::vector<std::string> PlayerSelector::Selector::getMap() const
{
    return _map->getMap();
}

void PlayerSelector::Selector::endMaps()
{
    camera->setPosition({0, 0, 10});

// FIXME: In constructor _map don't init when delete (byPRINCE)
/*    if (_map != nullptr)
        delete _map;*/
}

void PlayerSelector::Selector::nextMap()
{
    _map->next();
}

void PlayerSelector::Selector::prevMap()
{
    _map->prev();
}

size_t PlayerSelector::Selector::getMapType() const
{
    return _map->getMapType();
}

void PlayerSelector::Selector::next(const int &id)
{
    int next_id = (_players[id].getId() + 1 == _nbCharacters) ? 0 : _players[id].getId() + 1;

    _players[id] = Player(_charaDictionary[next_id].obj, _charaDictionary[next_id].texture, _charaDictionary[next_id].scalable, next_id, _charaDictionary[next_id].name, _charaDictionary[next_id].color, _charaDictionary[next_id].animations);
}

void PlayerSelector::Selector::prev(const int &id)
{
    int next_id = (_players[id].getId() - 1 < 0) ? _nbCharacters - 1 : _players[id].getId() - 1;

    _players[id] = Player(_charaDictionary[next_id].obj, _charaDictionary[next_id].texture, _charaDictionary[next_id].scalable, next_id, _charaDictionary[next_id].name, _charaDictionary[next_id].color, _charaDictionary[next_id].animations);
}
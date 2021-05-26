/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** XRay
*/

#include "XRay.hpp"

XRay::XRay()
    : _window(1920, 1080, "Bomberman")
{
    // Set resources
    setResources();

    // Scenes
    _scenesFunc.push_back(&XRay::displayMenuScene);
    _scenesFunc.push_back(&XRay::displayGameModeScene);
    _scenesFunc.push_back(&XRay::displayHowToPlayScene);
    _scenesFunc.push_back(&XRay::displaySettingsScene);
    _scenesFunc.push_back(&XRay::displayPlayerChoiceScene);
    _scenesFunc.push_back(&XRay::displayLoadGameScene);
    _scenesFunc.push_back(&XRay::displayInGameScene);
    _scenesFunc.push_back(&XRay::quitGame);

    // Display Intro (studio and introduction cinematic)
    _intro = std::make_pair(true, &XRay::displayStudio);
    displayCinematic(Cinematic::INTRO);
}

XRay::~XRay()
{
}

void XRay::setResources(void)
{
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::ADD, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/add.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::REMOVE, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/remove.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::PREVIOUS, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/previous.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::NEXT, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/next.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::CONTROLS, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/controls.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::GAMEPAD, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/gamepad.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::HUMAN, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/human.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::AI, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/ai.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::HEAD, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/head.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::LOADGAME, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/loadGame.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::LOADGAME_BG, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/loadGameBG.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::LOADGAME_HOVER, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/loadGameHover.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::NEWGAME, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/newGame.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::NEWGAME_BG, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/newGameBG.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::NEWGAME_HOVER, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/newGameHover.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::LOADSCENE, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/loadScene.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::BRANCH, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/branch.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::BACK, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/back.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::BACK_HOVER, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/backHover.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::HOW_TO_PLAY, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/howToPlay.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::HOW_TO_PLAY_HOVER, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/howToPlayHover.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::SETTINGS, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/settings.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::SETTINGS_HOVER, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/settingsHover.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::INDIE, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/indie.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::STUDIO, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/studio.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::BOMBER_TEAM, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/bomberTeam.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::MENU_TITLE, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/menuTitle.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::BOMBER_THINKING, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/bomberThinking.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::PLAY, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/play.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::PLAY_HOVER, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/playHover.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::QUIT, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/quit.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::QUIT_HOVER, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/quitHover.png"))));
}

bool XRay::mouseIsInBox(const std::vector<size_t> &box) const
{
    Raylib::Mouse mouse;

    if (box[UPPER_LEFT] <= mousePosition.first && mousePosition.first <= box[LOW_RIGHT]
    && box[LOW_LEFT] <= mousePosition.second && mousePosition.second <= box[UPPER_RIGHT])
        return true;
    return false;
}

std::vector<size_t> XRay::createBox(const size_t &upperLeftCorner, const size_t &upperRightCorner, const size_t &lowerLeftCorner, const size_t &lowerRightCorner) const
{
    std::vector<size_t> box;

    box.reserve(4);
    box.push_back(upperLeftCorner);
    box.push_back(upperRightCorner);
    box.push_back(lowerLeftCorner);
    box.push_back(lowerRightCorner);
    return box;
}

void XRay::displayInGameScene(void)
{
    // Set scene
    _scene = IN_GAME;

    // Draw scene
    beginDrawing();
    // Some code
    endDrawing();
}

void XRay::setTextBox(std::vector<bool> &mouseOnText, std::vector<::Rectangle> &textBox) // TODO: To change ?
{
    for (size_t p = 0, a = 200; p < 4; p++, a += 400) {
        _letterAndFrame.push_back(std::make_pair(0, 0));
        _userNames.push_back("");
        mouseOnText.push_back(false);
        if (p < _allIntegers[2])
            textBox.push_back({ (float)a, 180, 225, 50 });
    }
}

void XRay::updateTextBox(std::vector<bool> &mouseOnText, std::vector<::Rectangle> textBox) // TODO: To change ? // Remmove good player 
{
    for (size_t i = 0; i < mouseOnText.size(); i++) {
        mouseOnText[i] = (::CheckCollisionPointRec({(float)_mouse.getMouseX(), (float)_mouse.getMouseY()}, textBox[i])) ? true : false;
        if (mouseOnText[i]) {
            _mouse.setMouseCursor(MOUSE_CURSOR_IBEAM);

            for (int key = _keyboard.getCharPressed(); key > 0; key = _keyboard.getCharPressed())
                if ((key >= 32) && (key <= 125) && (_letterAndFrame[i].first < 9)) {
                    _userNames[i].push_back(key);
                    _letterAndFrame[i].first++;
                }

            if (_keyboard.isKeyPressed(KEY_BACKSPACE) && _userNames[i].size() > 0) {
                _letterAndFrame[i].first--;
                if (_letterAndFrame[i].first < 0)
                    _letterAndFrame[i].first = 0;
                else
                    _userNames[i].pop_back();
            }

        } else
            _mouse.setMouseCursor(MOUSE_CURSOR_DEFAULT);

        _letterAndFrame[i].second = (mouseOnText[i]) ? _letterAndFrame[i].second+1 : 0;
    }
}

void XRay::setAddBox(const std::vector<std::pair<int, int>> &removePos, const std::vector<std::pair<int, int>> &nextTab, const std::vector<std::pair<int, int>> &prevTab, const int &a)// TODO: To change ?
{
    _allIntegers[2] += (_allIntegers[2] != 4 && mouseIsInBox(createBox(_allIntegers[0]+a, _allIntegers[1], _allIntegers[0]+a+150, _allIntegers[1]+150)) && _mouse.isButtonPressed(0)) ? 1 : 0;
    if (_mouse.isButtonPressed(0))
        for (size_t u = 0; u < nextTab.size(); u++) {
            _playerTab[u] = (mouseIsInBox(createBox(nextTab[u].first, nextTab[u].second, nextTab[u].first+50, nextTab[u].second+49))) ? !_playerTab[u] : _playerTab[u];
            _playerTab[u] = (mouseIsInBox(createBox(prevTab[u].first, prevTab[u].second, prevTab[u].first+50, prevTab[u].second+49))) ? !_playerTab[u] : _playerTab[u];
            _controlsTab[u] = (mouseIsInBox(createBox(nextTab[u].first + 20, nextTab[u].second + 340, nextTab[u].first+70, nextTab[u].second+389)) && _playerTab[u]) ? !_controlsTab[u] : _controlsTab[u];
            _controlsTab[u] = (mouseIsInBox(createBox(prevTab[u].first - 20, prevTab[u].second + 340, prevTab[u].first + 20, prevTab[u].second+389))  && _playerTab[u]) ? !_controlsTab[u] : _controlsTab[u];
        }
    for (size_t u = 0; u < removePos.size(); u++) {
        _allIntegers[2] -= mouseIsInBox(createBox(removePos[u].first, removePos[u].second, removePos[u].first+64, removePos[u].second+63)) && _mouse.isButtonPressed(0) ? 1 : 0;
    }
}

void XRay::displayCards(const std::vector<bool> &mouseOnText, const std::vector<::Rectangle> &textBox)// TODO: To change ?
{
    Raylib::Text text;
    for (size_t p = 0; p < _allIntegers[2]; p++) {
        if (_playerTab[p]) {
            ::DrawRectangleRec(textBox[p], Raylib::Color::LightGray().getCStruct());
            (mouseOnText[p]) ? ::DrawRectangleLines(textBox[p].x, textBox[p].y, textBox[p].width, textBox[p].height, Raylib::Color::Red().getCStruct()) : ::DrawRectangleLines(textBox[p].x, textBox[p].y, textBox[p].width, textBox[p].height, Raylib::Color::DarkGray().getCStruct());
            ::DrawText(_userNames[p].c_str(), textBox[p].x + 5, textBox[p].y + 8, 40, Raylib::Color::Maroon().getCStruct());

            if (mouseOnText[p] && _letterAndFrame[p].first < 9)
                if (((_letterAndFrame[p].second/20)%2) == 0)
                    text.drawText("_", textBox[p].x + 8 + text.measureText(_userNames[p].c_str(), 40), textBox[p].y + 12, 40, Raylib::Color::Maroon());
        }
    }
}

void XRay::displayMouse(void)
{
    _resources.at(HEAD)->drawTexture(_mouse.getMouseX() - 32, _mouse.getMouseY() - 32, Raylib::Color::White());
}

void XRay::displayCardsSettings(std::vector<std::pair<int, int>> &removePos, std::vector<std::pair<int, int>> &nextTab, std::vector<std::pair<int, int>> &prevTab, int *a)// TODO: To change ?
{
    int i, b;
    for (i = 0, (*a) = 200, b = 300; _allIntegers[2] < 5 && i < _allIntegers[2]; i++, (*a) += 400) {
        _resources.at(PREVIOUS)->drawTexture((*a)-54, _allIntegers[1], Raylib::Color::White());
        if (_playerTab[i]) {
            (_controlsTab[i]) ? _resources.at(CONTROLS)->drawTexture((*a) - 30, _allIntegers[1] + 300, Raylib::Color::White()) : _resources.at(GAMEPAD)->drawTexture((*a) - 30, _allIntegers[1] + 300, Raylib::Color::White());
            _resources.at(PREVIOUS)->drawTexture((*a)-84, _allIntegers[1] + 340, Raylib::Color::White());
            _resources.at(NEXT)->drawTexture((*a)+250, _allIntegers[1] + 340, Raylib::Color::White());
        }
        (_playerTab[i]) ? _resources.at(HUMAN)->drawTexture((*a), b, Raylib::Color::White()) : _resources.at(AI)->drawTexture((*a), b, Raylib::Color::White());
        _resources.at(NEXT)->drawTexture((*a)+230, _allIntegers[1], Raylib::Color::White());
        nextTab.push_back(std::make_pair((*a)+230, _allIntegers[1]));
        prevTab.push_back(std::make_pair((*a)-54, _allIntegers[1]));
        if (i != 0) {
            removePos.push_back(std::make_pair((*a)+240, _allIntegers[1]-100));
            _resources.at(REMOVE)->drawTexture((*a) + 240, _allIntegers[1]-100, Raylib::Color::White());
        }
    }
    if (_allIntegers[2] != 4)
        _resources.at(ADD)->drawTexture(_allIntegers[0] + (*a), _allIntegers[1], Raylib::Color::White());
}

void XRay::displayPlayerChoiceScene(void) // TODO: To change ?
{
    // TODO: Put our encapsulation and Try to split function (Already did, but x_x)
    //Raylib::Texture head(Raylib::Image("resources/assets/head.png"));

    std::vector<std::pair<int, int>> removePos;
    std::vector<std::pair<int, int>> nextTab;
    std::vector<std::pair<int, int>> prevTab;

    std::vector<bool> mouseOnText;
    std::vector<::Rectangle> textBox;

    _scene = PLAYER_CHOICE;

    int a;

    setTextBox(mouseOnText, textBox);

    updateTextBox(mouseOnText, textBox);

    beginDrawing();

    displayCards(mouseOnText, textBox);
    displayCardsSettings(removePos, nextTab, prevTab, &a);
    displayMouse();
    endDrawing();

    setAddBox(removePos, nextTab, prevTab, a);

//    displayInGameScene();
}

void XRay::displayLoadGameScene(void)
{
    // Set scene
    _scene = LOAD_GAME;

    // Vertical axis
    size_t ordinate = 300;

    // Draw scene
    beginDrawing();
    _resources.at(LOADSCENE)->drawTexture(0, 0, Raylib::Color::White());
    Raylib::Text::drawText("BACKUPS", 230, 210, 65, Raylib::Color::Black());
    for (const std::string &backup : _backups) {
        _resources.at(BRANCH)->drawTexture(150, ordinate, Raylib::Color::White());
        Raylib::Text::drawText(backup.substr(0, backup.find('.')), 300, ordinate + 20, 65, Raylib::Color::Black());
        ordinate += 100;
    }
    endDrawing();
}

void XRay::displayGameModeScene(void)
{
    // Set scene
    _scene = GAME_MODE;

    // Check if mouse is on button spot
    bool goBack = mouseIsInBox(createBox(250, 900, 510, 965)) ? true : false;
    bool goNewGame = mouseIsInBox(createBox(180, 500, 700, 565)) ? true : false;
    bool goLoadGame = mouseIsInBox(createBox(1140, 500, 1660, 565)) ? true : false;

    // Set specific texture according to mouse position
    std::shared_ptr<Raylib::Texture> backButton = mouseIsInBox(createBox(250, 900, 510, 965)) ? _resources.at(BACK_HOVER) : _resources.at(BACK);
    std::shared_ptr<Raylib::Texture> newGameButton = mouseIsInBox(createBox(180, 500, 700, 565)) ? _resources.at(NEWGAME_HOVER) : _resources.at(NEWGAME);
    std::shared_ptr<Raylib::Texture> loadGameButton = mouseIsInBox(createBox(1140, 500, 1660, 565)) ? _resources.at(LOADGAME_HOVER) : _resources.at(LOADGAME);

    // Draw scene
    beginDrawing();
    _resources.at(NEWGAME_BG)->drawTexture(0, 0, Raylib::Color::White());
    _resources.at(LOADGAME_BG)->drawTexture(960, 0, Raylib::Color::White());
    backButton->drawTexture(250, 900, Raylib::Color::White());
    newGameButton->drawTexture(180, 500, Raylib::Color::White());
    loadGameButton->drawTexture(1140, 500, Raylib::Color::White());
    displayMouse();
    endDrawing();

    // Go to another scene according to mouse position
    if (goBack && _mouse.isButtonPressed(0))
        displayMenuScene();
    else if (goNewGame && _mouse.isButtonPressed(0))
        displayPlayerChoiceScene();
    else if (goLoadGame && _mouse.isButtonPressed(0))
        displayLoadGameScene();
}

void XRay::displayHowToPlayScene(void)
{
    // Set scene
    _scene = HOW_TO_PLAY;

    // Check if mouse is on button spot
    bool goBack = mouseIsInBox(createBox(20, 1000, 280, 1065)) ? true : false;

    // Set specific texture according to mouse position
    std::shared_ptr<Raylib::Texture> backButton = mouseIsInBox(createBox(20, 1000, 280, 1065)) ? _resources.at(BACK_HOVER) : _resources.at(BACK);

    // Draw scene
    beginDrawing();
    backButton->drawTexture(20, 1000, Raylib::Color::White());
    displayMouse();
    endDrawing();

    // Go to another scene according to mouse position
    if (goBack && _mouse.isButtonPressed(0))
        displayMenuScene();
}

void XRay::displaySettingsScene(void)
{
    // Set scene
    _scene = SETTINGS;

    // Check if mouse is on button spot
    bool goBack = mouseIsInBox(createBox(20, 1000, 280, 1065)) ? true : false;

    // Set specific texture according to mouse position
    std::shared_ptr<Raylib::Texture> backButton = mouseIsInBox(createBox(20, 1000, 280, 1065)) ? _resources.at(BACK_HOVER) : _resources.at(BACK);

    // Draw scene
    beginDrawing();
    backButton->drawTexture(20, 1000, Raylib::Color::White());
    displayMouse();
    endDrawing();

    // Go to another scene according to mouse position
    if (goBack && _mouse.isButtonPressed(0))
        displayMenuScene();
}

void XRay::quitGame(void)
{
    // Set scene
    _scene = END_GAME;
}

void XRay::displayStudio(void)
{
    // Draw
    beginDrawing();
    _resources.at(INDIE)->drawTexture(500, 1080 / 2 - 100, Raylib::Color::White());
    _resources.at(STUDIO)->drawTexture(900, 1080 / 2 - 100, Raylib::Color::White());
    endDrawing();

    // Intro is done, so update its status flag
    _intro.first = false;
}

void XRay::displayMenuScene(void)
{
    // Set scene
    _scene = MENU;

    // Check if mouse is on button spot
    bool goPlay = mouseIsInBox(createBox(100, 500, 360, 565)) ? true : false;
    bool goHowToPlay = mouseIsInBox(createBox(100, 600, 815, 665)) ? true : false;
    bool goSettings = mouseIsInBox(createBox(100, 700, 620, 765)) ? true : false;
    bool quit = mouseIsInBox(createBox(100, 800, 360, 865)) ? true : false;

    // Set specific texture according to mouse position
    std::shared_ptr<Raylib::Texture> playButton = mouseIsInBox(createBox(100, 500, 360, 565)) ? _resources.at(PLAY_HOVER) : _resources.at(PLAY);
    std::shared_ptr<Raylib::Texture> howToPlayButton = mouseIsInBox(createBox(100, 600, 815, 665)) ? _resources.at(HOW_TO_PLAY_HOVER) : _resources.at(Resources::HOW_TO_PLAY);
    std::shared_ptr<Raylib::Texture> settingsButton = mouseIsInBox(createBox(100, 700, 620, 765)) ? _resources.at(SETTINGS_HOVER) : _resources.at(Resources::SETTINGS);
    std::shared_ptr<Raylib::Texture> quitButton = mouseIsInBox(createBox(100, 800, 360, 865)) ? _resources.at(QUIT_HOVER) : _resources.at(QUIT);

    // Hide the cursor
    if (_cursor.isCursorOnScreen())
        _cursor.hideCursor();

    // Draw scene
    beginDrawing();
    _resources.at(MENU_TITLE)->drawTexture(1920 / 4 + 100, 40, Raylib::Color::White());
    _resources.at(BOMBER_THINKING)->drawTexture(1920 / 4 - 80, 130, Raylib::Color::White());
    _resources.at(BOMBER_TEAM)->drawTexture(1420, 600, Raylib::Color::White());
    playButton->drawTexture(100, 500, Raylib::Color::White());
    howToPlayButton->drawTexture(100, 600, Raylib::Color::White());
    settingsButton->drawTexture(100, 700, Raylib::Color::White());
    quitButton->drawTexture(100, 800, Raylib::Color::White());
    displayMouse();
    endDrawing();

    // Go to another scene according to mouse position
    if (goPlay && _mouse.isButtonPressed(0))
        displayGameModeScene();
    else if (goHowToPlay && _mouse.isButtonPressed(0))
        displayHowToPlayScene();
    else if (goSettings && _mouse.isButtonPressed(0))
        displaySettingsScene();
    else if (quit && _mouse.isButtonPressed(0))
        quitGame();
}

// TODO:
// -> Go to another scene : function pointer
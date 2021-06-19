/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-prince.miyigbena
** File description:
** Defeat
*/

#include "XRay.hpp"
#include "../../../Engine/Exception/MyException.hpp"

void XRay::goToAnotherSceneFromDefeat()
{
    // Check if mouse is on button spot
    bool home = mouseIsInBox(createBox(380, 330, 380+375, 330+65)) ? true : false;
    bool restart = mouseIsInBox(createBox(380, 440, 380+375, 440+65)) ? true : false;

    // Call function that check click on button
    if (restart && Raylib::Mouse::isButtonPressed(0)) {
        _sfx.at(SFX_KLICK)->play();
        _isPaused = false;
        m_isPaused = 2;
        _pointerToRestartFunc();
        displayCinematic("loading", 0, 0);
        displayInGameScene();
    }
    if (home && Raylib::Mouse::isButtonPressed(0)) {
        _sfx.at(SFX_KLICK)->play();
        _isPaused = false;
        m_isPaused = 2;
        _pointerToRestartFunc();
        resetAll();
        displayMenuScene();
    }
}

void XRay::displayDefeatScene()
{
    // Set scene
    _scene = DEFEAT;

    playMusic(MSC_BOMBERMAN);

    // Draw scene
    beginDrawing();
    _resources.at(DEFEATBG)->drawTexture(0, 0);
    (mouseIsInBox(createBox(380, 330, 380+375, 330+65)) ? _resources.at(HOMEHOVER) : _resources.at(HOME))->drawTexture(380, 330);
    (mouseIsInBox(createBox(380, 440, 380+375, 440+65)) ? _resources.at(RESTARTHOVER) : _resources.at(Resources::RESTART))->drawTexture(380, 440);
    _resources.at(RANKING)->drawTexture(1030, 350);
    displayMouse();
    endDrawing();

    // Call function that check click on button
    goToAnotherSceneFromDefeat();
}


// STANDARD EXCEPTION CLASS detection according to type of exceptions if one exists.
// catch
// throw
// try

int catchThrowTrygoToAnotherSceneFromDefeat() {
    try
    {   XRay test;
    	test.goToAnotherSceneFromDefeat();
    }
    catch (Engine::MyException& ex)
    {
    	std::cout << ex.what() << ex.get_info() << std::endl;
        std::cout << "Function: " << ex.get_func() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}


int catchThrowTrydisplayDefeatScenet() {
    try
    {   XRay test;
    	test.displayDefeatScene();
    }
    catch (Engine::MyException& ex)
    {
    	std::cout << ex.what() << ex.get_info() << std::endl;
        std::cout << "Function: " << ex.get_func() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}
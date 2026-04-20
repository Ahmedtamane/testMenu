#ifndef MAINMENU_H
#define MAINMENU_H

#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#include<sstream>
#include<iomanip>

using namespace sf;
using namespace std;

class Menu
{
private:
    // Game state
    enum GameState { MAIN_MENU, OPTIONS_MENU, LEVEL_SELECT };
    GameState currentState;

    // Font
    Font font;

    // Main menu elements
    Text menu[3];
    RectangleShape buttons[3];
    int selectedIndex;

    // Options menu elements
    Text optionsTitle;
    Text volumeText;
    Text volumeValue;
    Text backButton;
    RectangleShape volumeSlider;
    RectangleShape volumeKnob;
    RectangleShape backButtonRect;
    bool isDraggingKnob;

    // Level select elements
    Text levelTitle;
    RectangleShape levelBoxes[3];
    Text levelTexts[3];
    bool levelHover[3];
    int selectedLevel;
    RectangleShape levelBackButton;
    Text levelBackText;

    //level select images
    Texture levelTextures[3];
    Sprite levelSprites[3];

    // Volume
    float volumeLevel;

    // Backgrounds
    Texture bgTexture1;  // Main menu background
    Texture bgTexture2;  // Options menu background (additional)
    Sprite backgroundMain;     // For main menu
    Sprite backgroundOptions;  // For options menu (combines both)

    // Audio
    SoundBuffer buffer;
    Sound sound;
    Music music;

public:
    Menu(float width, float height);

    void draw(RenderWindow& window);
    void handleInput(RenderWindow& window, Event& event);

    // Main menu functions
    void moveUp();
    void moveDown();
    int getSelectedIndex();
    void handleMouseMainMenu(RenderWindow& window);

    // Options menu functions
    void handleMouseOptions(RenderWindow& window, Event& event);
    void updateVolume();
};

#endif
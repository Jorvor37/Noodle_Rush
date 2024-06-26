#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

using namespace sf;

/*
    Class that acts as the game engine.
    Wrapper class
*/

class Game
{
    private:
        //Variables
        //Window
        RenderWindow* window;
        Event ev;
        VideoMode videoMode;

        //Private Function
        void initVariable();
        void initWindow();


    public:
        //Constructors & Destructors
        Game();
        virtual ~Game();

        //Accessors
        const bool running() const;

        //Funstions
        void pollEvents();
        void update();
        void render();
};
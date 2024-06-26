#include "Game.h"

//Private Functions
void Game::initVariable(){
    this->window = nullptr;

}

void Game::initWindow(){
    this->videoMode.height = 1920;
    this->videoMode.width = 1080;
    //this->videoMode.getDesktopMode;
    this->window = new RenderWindow(VideoMode(1920,1080), "Ramen Rush", Style::Titlebar | Style::Close);
}

//Constructors & Destructors
Game::Game(){
    this->initVariable();
    this->initWindow();
}

Game::~Game(){
    delete this->window;
}

//Accessors
const bool Game::running() const{
    return this->window->isOpen();
}

//Functions
void Game::pollEvents(){
    while (this->window->pollEvent(this->ev))
        {
            switch (this->ev.type)
            {
            case Event::Closed:
                this->window->close();
                break;

            case Event::KeyPressed:
                if(this->ev.key.code == Keyboard::Escape)
                    this->window->close();
                break;
            
            default:
                break;
            }
        }
}

void Game::update(){
    this->pollEvents();
}

void Game::render(){
    /*
        @return void
        Render the game objects
            -Clear old frame
            -Render objects
            -displat frame in window
    */
    this->window->clear(Color(255,0,0,255));

    //draw game

    this->window->display();
}

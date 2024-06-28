#include <iostream>

#include "Game.h"

using namespace sf;

int main(){
    //Init game engine
    Game game;
    
    หวัดดีเห็นมั้ย 
    โย่ว ๆๆๆๆๆๆๆ
    //Game Loop
    while(game.running())
    {

        //Update
        game.update();

        //Render
        game.render();
        
    }
    
    //End of application


    return 0;
}
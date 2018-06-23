#include <iostream>
#include <SDL2/SDL.h>
#include "Screen.h"
using namespace std;

int main(int argc, char *argv[]){
    
    Screen screen;
    
    if(screen.init() == false){
        cout << "Error initalizing SDL" << endl;
    }
    
    while(true){
        // Update
        // Draw
        // Check for messages/events
        if(screen.processEvents() == false){
            break;
        }
       
    }
    
    screen.close();
    
    cout << "SDL Init succeeded" << endl;
    
    SDL_Quit();
    return 0;
}

//
//  Screen.h
//  SDL Tutorial
//
//  Created by dschlaepfer on 23.06.18.
//  Copyright © 2018 dschlaepfer. All rights reserved.
//

#ifndef Screen_h
#define Screen_h
#include <SDL2/SDL.h>

class Screen{
public:
    const static int SCREEN_WIDTH = 800;
    const static int SCREEN_HEIGHT = 600;
private:
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    SDL_Texture *m_texture;
    Uint32 *m_buffer;
    
public:
    Screen();
    bool init();
    bool processEvents();
    void close();
    
};


#endif /* Screen_h */

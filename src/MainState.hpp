//
//  MainState.hpp
//  SDL2_App
//
//  Created by Le Cheng on 16/04/2020.
//
#pragma once

#include "State.hpp"
#include "Button.hpp"
#include "ImageManager.h"
#ifndef MainState_hpp
#define MainState_hpp

#include <stdio.h>

#endif /* MainState_hpp */

class MainState:
    public State
{
public:
    MainState(Psylc7Engine *pEngine);
    ~MainState();
    void update();
    void SetUpBackgroundBuffer();
    void InitialiseObjects();
    void MouseDown(int iButton, int iX, int iY) ;
protected:
    Button* button1;
    PlayState* play;
    SimpleImage image;
    
};

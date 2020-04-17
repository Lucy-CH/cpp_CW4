//
//  PlayState.hpp
//  SDL2_App
//
//  Created by Le Cheng on 17/04/2020.
//
#pragma once
#include "State.hpp"

#ifndef PlayState_hpp
#define PlayState_hpp

#include <stdio.h>

#endif /* PlayState_hpp */

class PlayState:
    public State
{
public:
    PlayState(Psylc7Engine* pEngine);
    ~PlayState();
    void update();
    void SetUpBackgroundBuffer();
    void InitialiseObjects();
    void MouseDown(int iButton, int iX, int iY) ;
};

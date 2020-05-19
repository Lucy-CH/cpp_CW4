//
//  SuccessState.hpp
//  SDL2_App
//
//  Created by Le Cheng on 19/05/2020.
//
#pragma once
#include "State.hpp"
#include "Psylc7Engine.hpp"

#ifndef DeathState_hpp
#define DeathState_hpp

#include <stdio.h>

#endif /* DeathState_hpp */

class SuccessState
: public State
{
public:
    SuccessState(Psylc7Engine* pEngine);
    ~SuccessState();
 void SetUpBackgroundBuffer();
 void virtDrawStringsOnTop();
 void virtKeyDown(int iKeyCode);
 void InitialiseObjects();
 void update();
 void MouseDown(int iButton, int iX, int iY);
 int changeoffset();
    
 
protected:
    SimpleImage image;
    
};

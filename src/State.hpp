//
//  State.hpp
//  SDL2_App
//
//  Created by Le Cheng on 15/04/2020.
//
#pragma once
#include "header.h"
#include "Psylc7Engine.hpp"

#ifndef State_hpp
#define State_hpp

#include <stdio.h>

#endif /* State_hpp */

class State
{
public:
    State(Psylc7Engine* pEngine);
    ~State();
    virtual void update() = 0 ; //pure virtual function
    virtual void SetUpBackgroundBuffer() = 0;
    virtual void InitialiseObjects() = 0;
    virtual void MouseDown(int iButton, int iX, int iY) = 0;
    virtual void virtDrawStringsOnTop() =0;
protected:
    Psylc7Engine *engine;
    
};

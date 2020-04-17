//
//  Psylc7Engine.hpp
//  SDL2_App
//
//  Created by Le Cheng on 15/04/2020.
//
#pragma once
#include "header.h"
#include "BaseEngine.h"


#ifndef Psylc7Engine_hpp
#define Psylc7Engine_hpp

#include <stdio.h>

#endif /* Psylc7Engine_hpp */

class State;// forward declaring classes instead of using headers
class MainState;

class Psylc7Engine:
        public BaseEngine
{
public:
    Psylc7Engine();
    ~Psylc7Engine();
    void virtSetupBackgroundBuffer();
    int virtInitialiseObjects();
    void virtMouseDown(int iButton,int iX, int iY);
    void virtKeyDown(int iKeyCode);
    void setState(State* state);
    
    
protected:
    State* currentState;
    MainState* menu;
 
   
};

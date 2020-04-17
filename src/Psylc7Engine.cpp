//
//  Psylc7Engine.cpp
//  SDL2_App
//
//  Created by Le Cheng on 15/04/2020.
//
#include "header.h"
#include "Psylc7Engine.hpp"
#include "MainState.hpp"
#include "Button.hpp"
#include "JasonsObjectA.h"

Psylc7Engine::Psylc7Engine()
{
    menu = new MainState(this);
    currentState = menu;
}

Psylc7Engine::~Psylc7Engine()
{
    
}

void Psylc7Engine::virtSetupBackgroundBuffer()
{
    currentState->SetUpBackgroundBuffer();//white background
}
                 
int Psylc7Engine::virtInitialiseObjects()
{
    currentState->InitialiseObjects();
    
    return 0;
}

void Psylc7Engine::virtKeyDown(int iKeyCode)
{
    
}
void Psylc7Engine::setState(State *state)
{
    
}

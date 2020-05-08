//
//  Psylc7Engine.cpp
//  SDL2_App
//
//  Created by Le Cheng on 15/04/2020.
//
#include "header.h"
#include "Psylc7Engine.hpp"
#include "MainState.hpp"
#include "PlayState.hpp"
#include "PauseState.hpp"

Psylc7Engine::Psylc7Engine()

{
    menu = new MainState(this);
    play = new PlayState(this);
    pausestate= new PauseState(this);
    currentState = menu;
    
    is_resumed = false;
}

Psylc7Engine::~Psylc7Engine()
{
    
}

void Psylc7Engine::virtSetupBackgroundBuffer()
{
    
    currentState->SetUpBackgroundBuffer();
}

void Psylc7Engine::virtMouseDown(int iButton,int iX, int iY)
{
    currentState->MouseDown(iButton, iX, iY);
}
                 
int Psylc7Engine::virtInitialiseObjects()
{
    currentState->InitialiseObjects();
    
    return 0;
}

void Psylc7Engine::virtKeyDown(int iKeyCode)
{
    currentState->virtKeyDown(iKeyCode);
}
void Psylc7Engine::setState(State *state)
{
    this->currentState = state;
    this->virtSetupBackgroundBuffer();
    this->virtInitialiseObjects();

}

State* Psylc7Engine::isPlaying()
{
     return play;

}
State* Psylc7Engine::isPaused()
{
    return pausestate;
}

void Psylc7Engine::virtDrawStringsOnTop()
{

    currentState->virtDrawStringsOnTop();
}

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
    
    is_play_state = false;
    is_resumed = false;
    yellowkey1removed = false;
    greenslime1removed = false;
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
    is_play_state = true;
    return play;

}
State* Psylc7Engine::isPaused()
{
    is_play_state = false;
    return pausestate;
}

void Psylc7Engine::virtDrawStringsOnTop()
{

    currentState->virtDrawStringsOnTop();
}

void Psylc7Engine::virtMainLoopDoBeforeUpdate()
{
    if(is_play_state)
   {
       currentState->changeoffset();
       this->virtSetupBackgroundBuffer();
       return;
   }
else{return;}
}

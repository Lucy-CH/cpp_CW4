//
//  PlayState.cpp
//  SDL2_App
//
//  Created by Le Cheng on 17/04/2020.
//
#include "header.h"
#include "Psylc7Engine.hpp"

#include "PlayState.hpp"
PlayState::PlayState(Psylc7Engine* pEngine)
:State(pEngine)
{
    
}

PlayState::~PlayState()
{
    
}
void PlayState:: update()
{
    
}

void PlayState::SetUpBackgroundBuffer()
{
    engine->fillBackground(0xffffff);
}
void PlayState::InitialiseObjects()
{
    
}
void PlayState::MouseDown(int iButton, int iX, int iY)
{
    
}

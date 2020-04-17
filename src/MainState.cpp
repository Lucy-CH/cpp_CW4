//
//  MainState.cpp
//  SDL2_App
//
//  Created by Le Cheng on 16/04/2020.
//
#include "header.h"
#include "MainState.hpp"
#include "Button.hpp"

MainState::MainState(Psylc7Engine *pEngine)
    :State(pEngine)
{
    
}

MainState::~MainState()
{
    
}

void MainState::update()
{
    
}

void MainState::SetUpBackgroundBuffer()
{
    engine->fillBackground(0x02163B);
 
    engine->lockBackgroundForDrawing();
    engine->drawBackgroundOval(1151 - 30, 61 + 30, 1151 + 30, 61 - 30, 0xffff00);
    std::cout << "IT IS HEREEEEEEE" <<std::endl;
    engine->unlockBackgroundForDrawing();
    engine->redrawDisplay();
    
}
void MainState::InitialiseObjects()
{
    /* record the fact that the object array is going to be changed*/
    engine->drawableObjectsChanged();
    /* Destroy the existing objects*/
    engine->destroyOldObjects(true);
    /* Create an object array*/
    engine->createObjectArray(1);
    
    engine->storeObjectInArray(0,new Button(engine,"START GAME",400,200,200,50));
    engine->setAllObjectsVisible(true);
}
 void MainState::MouseDown(int iButton, int iX, int iY)
{

}

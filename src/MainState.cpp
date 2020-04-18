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
    image = engine->loadImage("preview-day-platformer.png",true);
    
    SimpleImage im2 = ImageManager::get()->resizeTo(image, engine->getWindowWidth(), engine->getWindowHeight()); 
    im2.renderImage(engine->getBackgroundSurface(), 0, 0,0,0, engine->getWindowWidth(), engine->getWindowHeight());
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
    button1 = new Button (engine,"START GAME",400,200,200,50);
    engine->storeObjectInArray(0,button1);
    
    engine->setAllObjectsVisible(true);
}
 void MainState::MouseDown(int iButton, int iX, int iY)
{
    printf("Mouse clicked at %d %d\n", iX, iY);
    if(button1->checkMouthClick(iX, iY)){
        printf("Hello\n");
        engine->setState(engine->isPlaying());
    }
    
}

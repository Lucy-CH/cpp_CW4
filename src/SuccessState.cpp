//
//  SuccessState.cpp
//  SDL2_App
//
//  Created by Le Cheng on 19/05/2020.
//
#include "header.h"
#include "SuccessState.hpp"

SuccessState::SuccessState(Psylc7Engine* pEngine)
    :State(pEngine)
{
    
}

SuccessState::~SuccessState()
{
    
}
void SuccessState::SetUpBackgroundBuffer()
{
    engine->lockBackgroundForDrawing();
    engine->fillBackground(0x000000);
    image = engine->loadImage("./gameres/Backgrounds/goodend_background.png",true);
         
    SimpleImage im2 = ImageManager::get()->resizeTo(image, engine->getWindowWidth(), engine->getWindowHeight());
         im2.renderImage(engine->getBackgroundSurface(), 0, 0,0,0, engine->getWindowWidth(), engine->getWindowHeight());
    engine->unlockBackgroundForDrawing();
    engine->redrawDisplay();
}
void SuccessState::virtDrawStringsOnTop()

{

    
    char pause[128];
    char pause1[128];
    char pause2[128];
    char pause3[128];
    char pause4[128];
    
    sprintf(pause, "ESCAPED!");
    sprintf(pause1, "Amazing! You survived among terrible monsters");
    sprintf(pause2, "now it is finally time to go home. You are");
    sprintf(pause3, "exhausted, yet the good gold you found");
    sprintf(pause4, "inside the dungeon was definitely worth a furtune.");
    engine->drawForegroundString(engine->getWindowWidth()*0.35+50, 150, pause, 0xffffff,NULL);
     
    engine->drawForegroundString(engine->getWindowWidth()*0.35, 200, pause1, 0xffffff, engine->getFont("Helvetica-Normal.ttf", 15));
    engine->drawForegroundString(engine->getWindowWidth()*0.35, 200+15, pause2, 0xffffff, engine->getFont("Helvetica-Normal.ttf", 15));
    engine->drawForegroundString(engine->getWindowWidth()*0.35-10, 200+15*2, pause3, 0xffffff, engine->getFont("Helvetica-Normal.ttf", 15));
    engine->drawForegroundString(engine->getWindowWidth()*0.35-10, 200+15*3, pause4, 0xffffff, engine->getFont("Helvetica-Normal.ttf", 15));
}
void SuccessState::virtKeyDown(int iKeyCode)
{
  if(iKeyCode ==SDLK_SPACE)
  {
      engine->setState(engine->isPlaying());
  }
}

void SuccessState::InitialiseObjects()
{

    engine->destroyOldObjects(true);
}

void SuccessState:: update()
{
    
}

void SuccessState::MouseDown(int iButton, int iX, int iY)
{

}
int SuccessState::changeoffset()
{
    return 0;
}

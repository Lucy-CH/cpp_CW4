//
//  PauseState.cpp
//  SDL2_App
//
//  Created by Le Cheng on 07/05/2020.
//
#include "header.h"
#include "PauseState.hpp"

PauseState::PauseState(Psylc7Engine* pEngine)
    :State(pEngine)
{
    
}

PauseState::~PauseState()
{
    
}
void PauseState::SetUpBackgroundBuffer()
{
    engine->lockBackgroundForDrawing();
    engine->fillBackground(0x000000);
    image = engine->loadImage("./gameres/Backgrounds/pause_background.png",true);
         
    SimpleImage im2 = ImageManager::get()->resizeTo(image, engine->getWindowWidth(), engine->getWindowHeight());
         im2.renderImage(engine->getBackgroundSurface(), 0, 0,0,0, engine->getWindowWidth(), engine->getWindowHeight());
    engine->unlockBackgroundForDrawing();
    engine->redrawDisplay();
}
void PauseState::virtDrawStringsOnTop()

{  

    
    char pause[128];
    char pause1[128];
    char pause2[128];
    char pause3[128];
     
    sprintf(pause, "GAME PAUSED");
    sprintf(pause1, "Press SPACE to resume");
    sprintf(pause2, "Hint: Not quite sure if you could win?");
    sprintf(pause3, "  Drink the potion for extra hp point...");
    
    engine->drawForegroundString(engine->getWindowWidth()*0.35+50, 150, pause, 0xffffff,NULL);
     
    engine->drawForegroundString(engine->getWindowWidth()*0.35, 200, pause1, 0xffffff, engine->getFont("Helvetica-Normal.ttf", 15));
    engine->drawForegroundString(engine->getWindowWidth()*0.35, 200+15, pause2, 0xffffff, engine->getFont("Helvetica-Normal.ttf", 15));
    engine->drawForegroundString(engine->getWindowWidth()*0.35-10, 200+15*2, pause3, 0xffffff, engine->getFont("Helvetica-Normal.ttf", 15));
}
void PauseState::virtKeyDown(int iKeyCode)
{
  if(iKeyCode ==SDLK_SPACE)
  {
      engine->setState(engine->isPlaying());
  }
}

void PauseState::InitialiseObjects()
{

    engine->destroyOldObjects(true);
}

void PauseState:: update()
{
    
}

void PauseState::MouseDown(int iButton, int iX, int iY)
{

}
int PauseState::changeoffset()
{
    return 0;
}

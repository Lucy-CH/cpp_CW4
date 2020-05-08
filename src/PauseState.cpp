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
    engine->unlockBackgroundForDrawing();
    engine->redrawDisplay();
}
void PauseState::virtDrawStringsOnTop()

{  printf("print?\n");
   char buf[128];
   sprintf(buf, "Game paused press esc to resume");
   engine->drawForegroundString(engine->getWindowWidth()*0.35, 100, buf, 0xffffff, engine->getFont("Helvetica-Normal.ttf", 15));
}
void PauseState::virtKeyDown(int iKeyCode)
{
  if(iKeyCode ==SDLK_ESCAPE)
  {
      engine->setState(engine->isPlaying());
  }
}

void PauseState::InitialiseObjects()
{

   // engine->destroyOldObjects(true);
}

void PauseState:: update()
{
    
}

void PauseState::MouseDown(int iButton, int iX, int iY)
{

}

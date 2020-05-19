//
//  DeathState.cpp
//  SDL2_App
//
//  Created by Le Cheng on 19/05/2020.
//

#include "DeathState.hpp"
#include "header.h"
#include "DeathState.hpp"

DeathState::DeathState(Psylc7Engine* pEngine)
    :State(pEngine)
{
    
}

DeathState::~DeathState()
{
    
}
void DeathState::SetUpBackgroundBuffer()
{
    engine->lockBackgroundForDrawing();
    engine->fillBackground(0x000000);
    image = engine->loadImage("./gameres/Backgrounds/death_background.png",true);
       
       SimpleImage im2 = ImageManager::get()->resizeTo(image, engine->getWindowWidth(), engine->getWindowHeight());
       im2.renderImage(engine->getBackgroundSurface(), 0, 0,0,0, engine->getWindowWidth(), engine->getWindowHeight());
       engine->unlockBackgroundForDrawing();
    engine->unlockBackgroundForDrawing();
    engine->redrawDisplay();
}
void DeathState::virtDrawStringsOnTop()

{
   char badend[128];
   char badend1[128];
   char badend2[128];
   char badend3[128];
    
   sprintf(badend, "GAME OVER");
   sprintf(badend1, "You desparately wanted to get home,");
   sprintf(badend2, "but death is already waiting upon you...");
   sprintf(badend3, "Hint: Maybe try find the sword and the shield?...");
   engine->drawForegroundString(engine->getWindowWidth()*0.35+50, 150, badend, 0xff0000,NULL);
    
   engine->drawForegroundString(engine->getWindowWidth()*0.35, 200, badend1, 0xff0000, engine->getFont("Helvetica-Normal.ttf", 15));
   engine->drawForegroundString(engine->getWindowWidth()*0.35, 200+15, badend2, 0xff0000, engine->getFont("Helvetica-Normal.ttf", 15));
   engine->drawForegroundString(engine->getWindowWidth()*0.35-10, 200+15*2, badend3, 0xff0000, engine->getFont("Helvetica-Normal.ttf", 15));
}
void DeathState::virtKeyDown(int iKeyCode)
{
  if(iKeyCode ==SDLK_SPACE)
  {
      engine->setState(engine->isPlaying());
  }
}

void DeathState::InitialiseObjects()
{

    engine->destroyOldObjects(true);
}

void DeathState:: update()
{
    
}

void DeathState::MouseDown(int iButton, int iX, int iY)
{

}
int DeathState::changeoffset()
{
    return 0;
}

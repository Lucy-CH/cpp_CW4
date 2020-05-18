//
//  FireBall.cpp
//  SDL2_App
//
//  Created by Le Cheng on 09/05/2020.
//
#include "header.h"
#include "FireBall.hpp"

FireBall::FireBall(Psylc7Engine* pEngine,int ix,int iy,Character* chara)
:MyDisplayableObject(pEngine,4,0,0,0,0,0)
,iconx(0)
,icony(0)
,pCharacter(chara)
{
    fireball = pEngine->loadImage("./gameres/Stuff/fireball.png",false);
    
    m_iStartDrawPosX = -16;
    m_iStartDrawPosY = -16;

    

}

FireBall::~FireBall()
{
    
}

void FireBall::virtDoUpdate(int iCurrentTime)
{
    std::cout<<SDL_GetTicks()/1000<<std::endl;
    CurrentTime = (SDL_GetTicks()/1000)%10;
    if(CurrentTime == 9){
        this->setVisible(false);
    }
}

void FireBall::virtDraw()
{
    if(!isVisible()){
        return;
    }
    
    int iTick = getEngine()->getModifiedTime()/20; // 1 per 20ms
    int iFrame = iTick%30;
      
    if(iFrame % 6 == 0) {
          icony = 0;
      }
    if(iFrame % 6 == 1) {
          icony = 32;
      }
    if(iFrame % 6 == 2) {
          icony = 64;
      }
    

       fireball.renderImageWithMask(getEngine()->getForegroundSurface(), iconx, icony, pCharacter->getCurrentX()-16+m_iStartDrawPosX, pCharacter->getCurrentY()+m_iStartDrawPosY, 32, 32);
}

void FireBall::setX(int iChange){this->m_iCurrentScreenX = iChange;}
void FireBall::setY(int iChange){this->m_iCurrentScreenY = iChange;}

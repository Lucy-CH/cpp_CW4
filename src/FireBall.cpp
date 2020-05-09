//
//  FireBall.cpp
//  SDL2_App
//
//  Created by Le Cheng on 09/05/2020.
//
#include "header.h"
#include "FireBall.hpp"

FireBall::FireBall(Psylc7Engine* pEngine,int ix,int iy)
:MyDisplayableObject(pEngine,4,0,0,0,0)
,iconx(0)
,icony(0)
{
    fireball = pEngine->loadImage("./gameres/Stuff/fireball.png",false);
    
    m_iStartDrawPosX = -16;
    m_iStartDrawPosY = -16;
    m_iCurrentScreenX = ix;
    m_iCurrentScreenY = iy;
    

}

FireBall::~FireBall()
{
    
}

void FireBall::virtDoUpdate(int iCurrentTime)
{
    
}

void FireBall::virtDraw()
{
    if(!isVisible()){
        return;
    }
    
       fireball.renderImageWithMask(getEngine()->getForegroundSurface(), iconx, icony, m_iCurrentScreenX+m_iStartDrawPosX, m_iCurrentScreenY+m_iStartDrawPosY, 32, 32);
}

//
//  GreenSlime.cpp
//  SDL2_App
//
//  Created by Le Cheng on 01/05/2020.
//
#include "header.h"
#include "GreenSlime.hpp"
//LIFE 35
//ATTACK 118
//DEFENCE 1
//GOLD 1

GreenSlime::GreenSlime(Psylc7Engine* pEngine, int iStartX,int iStartY, int id)
:MyDisplayableObject(pEngine,2,35,118,1,1,id)
{

     m_iStartDrawPosX = -16;
     m_iStartDrawPosY = -16;
     
     m_iCurrentScreenX = iStartX;
     m_iCurrentScreenY = iStartY;
     
    greenSlime= pEngine ->loadImage("./gameres/Monster/slime1.png",false);
     
}

GreenSlime::~GreenSlime()
{
    
}

void GreenSlime::virtDraw()
{
    if(!isVisible()){
        return;
    }
    
    greenSlime.renderImageWithMask(getEngine()->getForegroundSurface(), 0, 0, m_iCurrentScreenX+m_iStartDrawPosX,m_iCurrentScreenY+m_iStartDrawPosY,32,32);
}

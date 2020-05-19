//
//  Potion.cpp
//  SDL2_App
//
//  Created by Le Cheng on 19/05/2020.
//
#include "header.h"
#include "Potion.hpp"


Potion::Potion(Psylc7Engine* pEngine, int iStartX,int iStartY)
    :MyDisplayableObject(pEngine,8,0,0,0,0,0)

{
  
    m_iStartDrawPosX = -16;
    m_iStartDrawPosY = -16;
    
    m_iCurrentScreenX = iStartX;
    m_iCurrentScreenY = iStartY;
    
    potion= pEngine ->loadImage("./gameres/Stuff/Transparent_Icons.png",false);
    
}

Potion::~Potion()
{
    
}


void Potion::virtDraw()
{
    if(!isVisible()){
        return;
    }
    
    potion.renderImageWithMask(getEngine()->getForegroundSurface(), 0*32, 9*32, m_iCurrentScreenX+m_iStartDrawPosX,m_iCurrentScreenY+m_iStartDrawPosY,32,32);
}


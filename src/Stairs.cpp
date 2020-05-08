//
//  Stairs.cpp
//  SDL2_App
//
//  Created by Le Cheng on 08/05/2020.
//
#include "header.h"
#include "Stairs.hpp"

Stairs::Stairs(Psylc7Engine* pEngine, int iStartX,int iStartY)
:MyDisplayableObject(pEngine,3,0,0,0,0)
{
    
     m_iStartDrawPosX = -16;
     m_iStartDrawPosY = -16;
     
     m_iCurrentScreenX = iStartX;
     m_iCurrentScreenY = iStartY;
     
     stair = pEngine ->loadImage("./gameres/Stuff/staircase.png",false);
}
Stairs::~Stairs()
{
    
}

void Stairs::virtDraw()
{
      if(!isVisible()){
            return;
        }
        
        stair.renderImageWithMask(getEngine()->getForegroundSurface(), 0, 0, m_iCurrentScreenX+m_iStartDrawPosX,m_iCurrentScreenY+m_iStartDrawPosY,32,32);
    
}

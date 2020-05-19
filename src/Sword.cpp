//
//  Sword.cpp
//  SDL2_App
//
//  Created by Le Cheng on 19/05/2020.
//

#include "header.h"
#include "Sword.hpp"
Sword::Sword(Psylc7Engine* pEngine, int iStartX,int iStartY)
:MyDisplayableObject(pEngine,5,0,0,0,0,0)
{
    m_iStartDrawPosX = -16;
    m_iStartDrawPosY = -16;
     
    m_iCurrentScreenX = iStartX;
    m_iCurrentScreenY = iStartY;
     
    sword = pEngine ->loadImage("./gameres/Stuff/Transparent_icons.png",false);
}


Sword::~Sword()
{
    
}

void Sword::virtDraw()
{
    if(!isVisible()){
        return;
    }
    
    sword.renderImageWithMask(getEngine()->getForegroundSurface(), 4*32, 5*32, m_iCurrentScreenX+m_iStartDrawPosX,m_iCurrentScreenY+m_iStartDrawPosY,32,32);
}

//
//  Shield.cpp
//  SDL2_App
//
//  Created by Le Cheng on 19/05/2020.
//
#include "header.h"
#include "Shield.hpp"

Shield::Shield(Psylc7Engine* pEngine, int iStartX,int iStartY)
:MyDisplayableObject(pEngine,4,0,0,0,0,0)
{
    m_iStartDrawPosX = -16;
    m_iStartDrawPosY = -16;
     
    m_iCurrentScreenX = iStartX;
    m_iCurrentScreenY = iStartY;
     
    shield= pEngine ->loadImage("./gameres/Stuff/Transparent_icons.png",false);
}


Shield::~Shield()
{
    
}

void Shield::virtDraw()
{
    if(!isVisible()){
        return;
    }
    
    shield.renderImageWithMask(getEngine()->getForegroundSurface(), 2*32, 6*32, m_iCurrentScreenX+m_iStartDrawPosX,m_iCurrentScreenY+m_iStartDrawPosY,32,32);
}

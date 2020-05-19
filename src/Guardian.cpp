//
//  Guardian.cpp
//  SDL2_App
//
//  Created by Le Cheng on 19/05/2020.
//
#include "header.h"
#include "Guardian.hpp"
Guardian::Guardian(Psylc7Engine* pEngine, int iStartX,int iStartY, int id)
:MyDisplayableObject(pEngine,2,35,210,1,50,id)
{

     m_iStartDrawPosX = -16;
     m_iStartDrawPosY = -16;
     
     m_iCurrentScreenX = iStartX;
     m_iCurrentScreenY = iStartY;
     
     guardian= pEngine ->loadImage("./gameres/Monster/Guardian.png",false);
     
}

Guardian::~Guardian()
{
    
}

void Guardian::virtDraw()
{
    if(!isVisible()){
        return;
    }
    
    guardian.renderImageWithMask(getEngine()->getForegroundSurface(), 0, 0, m_iCurrentScreenX+m_iStartDrawPosX,m_iCurrentScreenY+m_iStartDrawPosY,32,32);
}

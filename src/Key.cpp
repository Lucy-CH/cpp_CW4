//
//  Key.cpp
//  SDL2_App
//
//  Created by Le Cheng on 01/05/2020.
//
#include "header.h"
#include "Key.hpp"

Key::Key(Psylc7Engine* pEngine, int iStartX,int iStartY)
    :DisplayableObject(pEngine)
    ,value(1)
{
    m_iStartDrawPosX = -16;
    m_iStartDrawPosY = -16;
    
    m_iCurrentScreenX = iStartX;
    m_iCurrentScreenY = iStartY;
    
    yellowkey= pEngine ->loadImage("./gameres/Stuff/Transparent_Icons.png",false);
    
    
}

Key::~Key()
{
    
}

void Key::virtDraw()
{
    if(!isVisible()){
        return;
    }
    
    yellowkey.renderImageWithMask(getEngine()->getForegroundSurface(), 288, 352, m_iCurrentScreenX+m_iStartDrawPosX,m_iCurrentScreenY+m_iStartDrawPosY,32,32);
}

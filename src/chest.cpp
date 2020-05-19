//
//  chest.cpp
//  SDL2_App
//
//  Created by Le Cheng on 19/05/2020.
//

#include "chest.hpp"

chest::chest(Psylc7Engine* pEngine, int iStartX,int iStartY)
    :MyDisplayableObject(pEngine,6,0,0,0,0,0)

{
  
    m_iStartDrawPosX = -16;
    m_iStartDrawPosY = -16;
    
    m_iCurrentScreenX = iStartX;
    m_iCurrentScreenY = iStartY;
    
    chest1 = pEngine ->loadImage("./gameres/Stuff/Transparent_Icons.png",false);
    
    
}

chest::~chest()
{
    
}


void chest::virtDraw()
{
    if(!isVisible()){
        return;
    }
    
    chest1.renderImageWithMask(getEngine()->getForegroundSurface(), 11*32, 11*32, m_iCurrentScreenX+m_iStartDrawPosX,m_iCurrentScreenY+m_iStartDrawPosY,32,32);
}


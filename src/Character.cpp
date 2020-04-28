//
//  Character.cpp
//  SDL2_App
//
//  Created by Le Cheng on 27/04/2020.
//
#include "header.h"
#include "Character.hpp"

Character::Character(Psylc7Engine* pEngine)
    :DisplayableObject(pEngine)
{
    character = pEngine -> loadImage("./gameres/Character/Hero.png",false);
    m_iStartDrawPosX = -16;
    m_iStartDrawPosY = -16;
    
    m_iCurrentScreenX = (getEngine()->getWindowWidth())/2;
    m_iCurrentScreenY = (getEngine()->getWindowHeight()) - 32;
}

Character::~Character()
{
    
}

void Character::virtDraw()
{
    if(!isVisible()){
        return;
    }
    
    character.renderImageWithMask(getEngine()->getForegroundSurface(), 32, 0, m_iCurrentScreenX+m_iStartDrawPosX, m_iCurrentScreenY+m_iStartDrawPosY, 32, 32);
}


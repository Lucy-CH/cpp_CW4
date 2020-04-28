//
//  Statusbox.cpp
//  SDL2_App
//
//  Created by Le Cheng on 28/04/2020.
//
#include "header.h"

#include "Statusbox.hpp"

Statusbox::Statusbox(Psylc7Engine* pEngine)
           :DisplayableObject(pEngine)
{
    m_iCurrentScreenX = 0;
    m_iCurrentScreenY = 480;
    m_iDrawWidth = 640;
    m_iDrawHeight = 160;
}

Statusbox::~Statusbox()
{
    
}

void Statusbox::virtDraw()
{
    getEngine()->drawForegroundRectangle(
        m_iCurrentScreenX, m_iCurrentScreenY,
        m_iCurrentScreenX + m_iDrawWidth - 1,
        m_iCurrentScreenY + m_iDrawHeight - 1,
        0xF9E4B7);
}


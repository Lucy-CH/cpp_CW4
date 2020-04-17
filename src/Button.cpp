//
//  Button.cpp
//  SDL2_App
//
//  Created by Le Cheng on 16/04/2020.
//

#include "Button.hpp"

Button::Button(Psylc7Engine* pEngine, char* text, int xPos,int yPos,int width,int height)
:DisplayableObject(pEngine)
{
    this->m_text = text;
    /* Current Position on the screen*/
    this->m_iCurrentScreenX = xPos;
    this->m_iCurrentScreenY = yPos;
    /* Our button is a rectangle, these define the size of the rectangle */
    this->m_iDrawWidth = width;
    this->m_iDrawHeight = height;

}

Button::~Button()
{
    
    
}

void Button::virtDraw()
{
    getEngine()->drawForegroundRectangle(
        m_iCurrentScreenX, m_iCurrentScreenY,
        m_iCurrentScreenX + m_iDrawWidth - 1,
        m_iCurrentScreenY + m_iDrawHeight - 1,
        0x000000);
    
    getEngine()->drawForegroundString( m_iCurrentScreenX+8,m_iCurrentScreenY+8,this->m_text,0xffffff,NULL );
}

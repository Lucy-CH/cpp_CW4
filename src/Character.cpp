//
//  Character.cpp
//  SDL2_App
//
//  Created by Le Cheng on 27/04/2020.
//
#include "header.h"
#include "Character.hpp"

Character::Character(Psylc7Engine* pEngine,int ix,int iy)
    :DisplayableObject(pEngine)
{
    hp = 1000;
    atk = 100;
    def = 100;
    gold = 0;
    
    iconx = 32;
    icony = 0;
    
    
    
    character = pEngine -> loadImage("./gameres/Character/Hero.png",false);
    m_iStartDrawPosX = -32;
    m_iStartDrawPosY = -32;
    
    m_iCurrentScreenX = ix;
    m_iCurrentScreenY = iy;
}

Character::~Character()
{
    
}
//Accessors
int Character::gethp(){return this->hp;}
int Character::getatk(){return this->atk;}
int Character::getdef()  {return this->def;}
int Character::getgold()  {return this->gold;}

//Modifiers
void Character::sethp(int iChange){this->hp += iChange;}
void Character::setatk(int iChange){this->atk += iChange;}
void Character::setdef(int iChange){this->def += iChange;}
void Character::setgold(int iChange){this->gold += iChange;}

void Character::virtDraw()
{
    if(!isVisible()){
        return;
    }
    
    character.renderImageWithMask(getEngine()->getForegroundSurface(), iconx, icony, m_iCurrentScreenX+m_iStartDrawPosX, m_iCurrentScreenY+m_iStartDrawPosY, 32, 32);
}

void Character::virtDoUpdate(int iCurrentTime)
{
 
    
    if (getEngine()->isKeyPressed(SDLK_UP))
    {
        m_iCurrentScreenY -= 2;
        icony = 32*3;
        MoveBodyImage();

    }
    if (getEngine()->isKeyPressed(SDLK_DOWN))
    {
         m_iCurrentScreenY += 2;
         icony = 32*0;
         MoveBodyImage();
    }
       
    if (getEngine()->isKeyPressed(SDLK_LEFT))
    {
        m_iCurrentScreenX -= 2;
        icony = 32*1;
        MoveBodyImage();
    }
      

    if (getEngine()->isKeyPressed(SDLK_RIGHT))
    {
        m_iCurrentScreenX += 2;
        icony = 32*2;
        MoveBodyImage();
    }
        
   


    this->redrawDisplay();
}

void Character::MoveBodyImage(){
    
     int iTick = getEngine()->getModifiedTime()/100; // 1 per 100ms
     int iFrame = iTick%30 +30;
     
     if(iFrame % 3 == 0) {
         iconx = 0;
     }
     
     if(iFrame % 3 == 1) {
         iconx = 32;
     }
            
     if(iFrame % 3 == 2) {
         iconx = 64;
     }
}


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
    hp = 1000;
    atk = 100;
    def = 100;
    gold = 0;
    
    character = pEngine -> loadImage("./gameres/Character/Hero.png",false);
    m_iStartDrawPosX = -16;
    m_iStartDrawPosY = -16;
    
    m_iCurrentScreenX = (getEngine()->getWindowWidth())/2;
    m_iCurrentScreenY = (getEngine()->getWindowHeight()) - 16 -160;
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
    
    character.renderImageWithMask(getEngine()->getForegroundSurface(), 32, 0, m_iCurrentScreenX+m_iStartDrawPosX, m_iCurrentScreenY+m_iStartDrawPosY, 32, 32);
}


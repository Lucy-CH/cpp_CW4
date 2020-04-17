//
//  Character.cpp
//  SDL2_App
//
//  Created by Le Cheng on 16/04/2020.
//
#include "header.h"
#include "Character.hpp"


Character::Character(Psylc7Engine* pEngine)
:DisplayableObject(pEngine)
{
    level = 1;
    exp = 0;
    expNext = 0;
    hp = 0;
    attack = 0;
    defence = 0;
    
}

Character::~Character()
{
    
}

void Character::initialize(int level)
{
    this->level = level;
    
    this->exp = 0;
    this->expNext = round( 0.04 * (level ^ 3) + 0.8 * (level ^ 2) + 2 * level);//exp point: 3 8 14 23 35
    this->hp = 10 +level; //!needs change later
    this->attack = 10+level;
    this->defence = 10+level;
}

void Character::virtDraw()
{
    
}
void Character::virtDoUpdate(int iCurrentTime)
{
    
}


//
//  Character.hpp
//  SDL2_App
//
//  Created by Le Cheng on 27/04/2020.
//
#pragma once
#include "DisplayableObject.h"
#include "Psylc7Engine.hpp"

#ifndef Character_hpp
#define Character_hpp

#include <stdio.h>

#endif /* Character_hpp */

class Character:
    public DisplayableObject
{
public:
    friend class Statusbox;
    Character(Psylc7Engine* pEngine);
    ~Character();
    void virtDraw();
    //Accessors
    int gethp();
    int getatk();
    int getdef();
    int getgold();
    
    //Modifiers
    void sethp(int iChange);
    void setatk(int iChange);
    void setdef(int iChange);
    void setgold(int iChange);
    
    
protected:
    SimpleImage character;
    int hp;
    int atk;
    int def;
    int gold;
    

    
};

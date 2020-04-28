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
    Character(Psylc7Engine* pEngine);
    ~Character();
    void virtDraw();
    //Accessors
    inline const int& gethp() const {return this->hp;}
    inline const int& getatk() const {return this->atk;}
    inline const int& getdef() const {return this->def;}
    inline const int& getgold() const {return this->gold;}
    
    //Modifiers
    void sethp(int iChange){this->hp += iChange;}
    void setatk(int iChange){this->atk += iChange;}
    void setdef(int iChange){this->def += iChange;}
    void setgold(int iChange){this->gold += iChange;}
    
protected:
    SimpleImage character;
    int hp;
    int atk;
    int def;
    int gold;
    
};

//
//  Character.hpp
//  SDL2_App
//
//  Created by Le Cheng on 16/04/2020.
//
#pragma once
#include "DisplayableObject.h"
#include "Psylc7Engine.hpp"
#ifndef Character_hpp
#define Character_hpp

#include <stdio.h>

#endif /* Character_hpp */
#include <string>


class Character:
    public DisplayableObject
{
public:
    Character(Psylc7Engine* pEngine);
    ~Character();
    //Functions
    /* Depends on the level initialize characters*/
    void initialize(int level);
    void virtDraw();
    void virtDoUpdate(int iCurrentTime);
    //Accessors
    inline const double& getXpos() const{return this->xPos;}
    inline const double& getYpos() const{return this->yPos;}

    
    inline const int& getLevel() const {return this->level;}
    inline const int& getExp() const {return this->exp;}
    inline const int& getExpNext() const{return this->expNext;}
     
    inline const int& gethp() const {return this->hp;}
    inline const int& getAttack() const {return this->attack;}
    inline const int& getDefence() const {return this->defence;}
    
private:
    double xPos;
    double yPos;

    
    int level;
    int exp;
    int expNext;
    int hp;
    int attack;
    int defence;
protected:
    SimpleImage image;
};

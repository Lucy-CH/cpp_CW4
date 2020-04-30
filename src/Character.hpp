//
//  Character.hpp
//  SDL2_App
//
//  Created by Le Cheng on 27/04/2020.
//
#pragma once
#include "DisplayableObject.h"
#include "Psylc7Engine.hpp"
#include "Psylc7TileManager.hpp"

#ifndef Character_hpp
#define Character_hpp

#include <stdio.h>

#endif /* Character_hpp */

class Character:
    public DisplayableObject
{
public:
    friend class Statusbox;
    Character(Psylc7Engine* pEngine,int ix,int iy, Psylc7TileManager* pTile);
    ~Character();
    void virtDraw();
    void virtDoUpdate(int iCurrentTime);
    void MoveBodyImage();
    int checkTileNumber();
    
    //Accessors
    int gethp();
    int getatk();
    int getdef();
    int getgold();
    int getCurrentX(){return m_iCurrentScreenX;}
    int getCurrentY(){return m_iCurrentScreenY;}
    
    //Modifiers
    void sethp(int iChange);
    void setatk(int iChange);
    void setdef(int iChange);
    void setgold(int iChange);
    
    
    
protected:
    SimpleImage character;
    Psylc7TileManager* Ptile;
    int hp;
    int atk;
    int def;
    int gold;
    
    int iconx;
    int icony;
    


    
};

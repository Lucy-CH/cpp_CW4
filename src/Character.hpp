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
#include "MyDisplayableObject.hpp"
#ifndef Character_hpp
#define Character_hpp

#include <stdio.h>

#endif /* Character_hpp */

class Character:
    public MyDisplayableObject
{
public:

    Character(Psylc7Engine* pEngine,int ix,int iy, Psylc7TileManager* pTile);
    ~Character();
    void virtDraw();
    void virtDoUpdate(int iCurrentTime);
    void MoveBodyImage();
    void MouseDown(int iButton, int iX, int iY);

    
   

    //Accessors
    int gethp();
    int getatk();
    int getdef();
    int getgold();
    int getCurrentX(){return this->m_iCurrentScreenX;}
    int getCurrentY(){return this->m_iCurrentScreenY;}
    int getKeyNumber(){return this->key;}
  
    
    //Modifiers
    void sethp(int iChange);
    void setatk(int iChange);
    void setdef(int iChange);
    void setgold(int iChange);
    void setkey(int iChange);
    void setX(int iChange);
    void setY(int iChange);
    
    
    
protected:
    SimpleImage character;
    Psylc7TileManager* Ptile;
    Psylc7Engine* pEngineMain;
    int hp;
    int atk;
    int def;
    int gold;
    
    int iconx;
    int icony;
    
    int key;



    
};

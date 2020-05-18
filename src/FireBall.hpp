//
//  FireBall.hpp
//  SDL2_App
//
//  Created by Le Cheng on 09/05/2020.
//
#pragma once
#include "MyDisplayableObject.hpp"
#include "Psylc7Engine.hpp"
#ifndef FireBall_hpp
#define FireBall_hpp
#include "Character.hpp"

#include <stdio.h>

#endif /* FireBall_hpp */

class FireBall:
    public MyDisplayableObject
{
public:
    FireBall(Psylc7Engine* pEngine,int ix,int iy,Character* chara);
    ~FireBall();
    void virtDraw();
    void virtDoUpdate(int iCurrentTime);
    
    //setter for position
    void setX(int iChange);
    void setY(int iChange);
protected:
    SimpleImage fireball;
    Character* pCharacter;
    int iconx;
    int icony;
    int CurrentTime;
};


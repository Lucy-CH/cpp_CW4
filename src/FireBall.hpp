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

#include <stdio.h>

#endif /* FireBall_hpp */

class FireBall:
    public MyDisplayableObject
{
public:
    FireBall(Psylc7Engine* pEngine,int ix,int iy);
    ~FireBall();
    void virtDraw();
    void virtDoUpdate(int iCurrentTime);
    
protected:
    SimpleImage fireball;
    int iconx;
    int icony;
    
};


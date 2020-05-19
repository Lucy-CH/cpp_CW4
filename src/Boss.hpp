//
//  Boss.hpp
//  SDL2_App
//
//  Created by Le Cheng on 19/05/2020.
//
#pragma once
#include "MyDisplayableObject.hpp"
#include "Psylc7Engine.hpp"

#ifndef Boss_hpp
#define Boss_hpp

#include <stdio.h>

#endif /* Boss_hpp */

class Boss
     :public MyDisplayableObject
{
public:
    Boss(Psylc7Engine* pEngine,int ix,int iy);
    ~Boss();
    
    void virtDraw();
    void virtDoUpdate(int iCurrentTime);
protected:
    SimpleImage monster_boss;
    std::string state;
    int currentTime;
    
};

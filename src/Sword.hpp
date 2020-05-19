//
//  Sword.hpp
//  SDL2_App
//
//  Created by Le Cheng on 19/05/2020.
//
#pragma once
#include "MyDisplayableObject.hpp"
#include "Psylc7Engine.hpp"

#ifndef Sword_hpp
#define Sword_hpp

#include <stdio.h>

#endif /* Sword_hpp */
class Sword:
public MyDisplayableObject
{
public:
    Sword(Psylc7Engine* pEngine, int iStartX,int iStartY);
    ~Sword();
    
    void virtDraw();
protected:
    SimpleImage sword;
};

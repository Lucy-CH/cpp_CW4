//
//  MyDisplayableObject.hpp
//  SDL2_App
//
//  Created by Le Cheng on 01/05/2020.
//
#pragma once
#ifndef MyDisplayableObject_hpp
#define MyDisplayableObject_hpp
#include "DisplayableObject.h"
#include "Psylc7Engine.hpp"

#include <stdio.h>

#endif /* MyDisplayableObject_hpp */

class MyDisplayableObject:
public DisplayableObject
{
public:
    MyDisplayableObject(Psylc7Engine* pEngine,int id,int L,int A, int D, int G,int ident);
    ~MyDisplayableObject();
    
    int value;
    int life;
    int attack;
    int defence;
    int gold;
    int identifier;
    
    
};

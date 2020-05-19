//
//  Potion.hpp
//  SDL2_App
//
//  Created by Le Cheng on 19/05/2020.
//
#pragma once
#include "MyDisplayableObject.hpp"
#include "Psylc7Engine.hpp"

#ifndef Potion_hpp
#define Potion_hpp

#include <stdio.h>

#endif /* Potion_hpp */
class Potion:
    public MyDisplayableObject
{
public:
    Potion(Psylc7Engine* pEngine, int iStartX,int iStartY);
    ~Potion();
    void virtDraw();

protected:
    SimpleImage potion;

};

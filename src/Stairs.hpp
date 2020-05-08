//
//  Stairs.hpp
//  SDL2_App
//
//  Created by Le Cheng on 08/05/2020.
//
#pragma once
#include "MyDisplayableObject.hpp"
#include "Psylc7Engine.hpp"

#ifndef Stairs_hpp
#define Stairs_hpp

#include <stdio.h>

#endif /* Stairs_hpp */
class Stairs:
    public MyDisplayableObject
{
public:
    Stairs(Psylc7Engine* pEngine, int iStartX,int iStartY);
    ~Stairs();
    void virtDraw();
protected:
    SimpleImage stair;
};

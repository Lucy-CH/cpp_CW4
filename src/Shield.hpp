//
//  Shield.hpp
//  SDL2_App
//
//  Created by Le Cheng on 19/05/2020.
//
#pragma once
#include "MyDisplayableObject.hpp"
#include "Psylc7Engine.hpp"

#ifndef Shield_hpp
#define Shield_hpp

#include <stdio.h>

#endif /* Shield_hpp */

class Shield:
public MyDisplayableObject
{
public:
    Shield(Psylc7Engine* pEngine, int iStartX,int iStartY);
    ~Shield();
    
    void virtDraw();
protected:
    SimpleImage shield;
};

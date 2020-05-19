//
//  chest.hpp
//  SDL2_App
//
//  Created by Le Cheng on 19/05/2020.
//
#pragma once
#include "MyDisplayableObject.hpp"
#include "Psylc7Engine.hpp"

#ifndef chest_hpp
#define chest_hpp

#include <stdio.h>

#endif /* chest_hpp */
class chest:
    public MyDisplayableObject
{
public:
    chest(Psylc7Engine* pEngine, int iStartX,int iStartY);
    ~chest();
    void virtDraw();

    int getvalue();
    int value;
protected:
    SimpleImage chest1;

};

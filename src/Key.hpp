//
//  Key.hpp
//  SDL2_App
//
//  Created by Le Cheng on 01/05/2020.
//
#pragma once
#include "DisplayableObject.h"
#include "Psylc7Engine.hpp"

#ifndef Key_hpp
#define Key_hpp

#include <stdio.h>

#endif /* Key_hpp */

class Key:
    public DisplayableObject
{
public:
    Key(Psylc7Engine* pEngine, int iStartX,int iStartY);
    ~Key();
    void virtDraw();
    
protected:
    SimpleImage yellowkey;
    int value;
};

//
//  Character.hpp
//  SDL2_App
//
//  Created by Le Cheng on 27/04/2020.
//
#pragma once
#include "DisplayableObject.h"
#include "Psylc7Engine.hpp"

#ifndef Character_hpp
#define Character_hpp

#include <stdio.h>

#endif /* Character_hpp */

class Character:
    public DisplayableObject
{
public:
    Character(Psylc7Engine* pEngine);
    ~Character();
    void virtDraw();
    
private:
    SimpleImage character;
    
};

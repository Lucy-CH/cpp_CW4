//
//  Statusbox.hpp
//  SDL2_App
//
//  Created by Le Cheng on 28/04/2020.
//
#pragma once
#include "DisplayableObject.h"
#include "Psylc7Engine.hpp"

#ifndef Statusbox_hpp
#define Statusbox_hpp

#include <stdio.h>

#endif /* Statusbox_hpp */

class Statusbox:
    public DisplayableObject
{
public:
    Statusbox(Psylc7Engine* pEngine);
    ~Statusbox();
    void virtDraw();
    
protected:
    
};

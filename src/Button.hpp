//
//  Button.hpp
//  SDL2_App
//
//  Created by Le Cheng on 16/04/2020.
//
#pragma once
#include "DisplayableObject.h"
#include "Psylc7Engine.hpp"
#ifndef Button_hpp
#define Button_hpp

#include <stdio.h>

#endif /* Button_hpp */

class Button:
    public DisplayableObject
{
public:
    Button(Psylc7Engine* pEngine,std::string text,int xPos,int yPos, int width,int height);
    ~Button();
    
    void virtDraw();
private:
    std::string m_text;
    Psylc7Engine* engine;
    
};

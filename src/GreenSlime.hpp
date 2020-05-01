//
//  GreenSlime.hpp
//  SDL2_App
//
//  Created by Le Cheng on 01/05/2020.
//
#pragma once
#include "MyDisplayableObject.hpp"
#include "Psylc7Engine.hpp"


#ifndef GreenSlime_hpp
#define GreenSlime_hpp

#include <stdio.h>

#endif /* GreenSlime_hpp */
class GreenSlime:
    public MyDisplayableObject
{
public:
    GreenSlime(Psylc7Engine* pEngine, int iStartX,int iStartY);
    ~GreenSlime();
    void virtDraw();

protected:
    SimpleImage greenSlime;

};

//
//  Guardian.hpp
//  SDL2_App
//
//  Created by Le Cheng on 19/05/2020.
//
#pragma once
#include "MyDisplayableObject.hpp"
#include "Psylc7Engine.hpp"

#ifndef Guardian_hpp
#define Guardian_hpp

#include <stdio.h>

#endif /* Guardian_hpp */
class Guardian
     :public MyDisplayableObject
{
public:
    Guardian(Psylc7Engine* pEngine,int ix,int iy,int id);
    ~Guardian();
    
    void virtDraw();
   
protected:
    SimpleImage guardian;
   
    
};

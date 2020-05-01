//
//  MyDisplayableObject.cpp
//  SDL2_App
//
//  Created by Le Cheng on 01/05/2020.
//
#include "header.h"
#include "MyDisplayableObject.hpp"

//L LIFE
//A ATTACK
//D DEFENCE
//G GOLD

MyDisplayableObject::MyDisplayableObject(Psylc7Engine* pEngine,int id,int L,int A, int D, int G)
:DisplayableObject(pEngine)
,value(id)
,life(L)
,attack(A)
,defence(D)
,gold(G)

{
    
}

MyDisplayableObject::~MyDisplayableObject()
{
    
}

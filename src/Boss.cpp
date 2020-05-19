//
//  Boss.cpp
//  SDL2_App
//
//  Created by Le Cheng on 19/05/2020.
//
#include "header.h"
#include "Boss.hpp"
/*
 Boss has id 2, since it's a monster
 Life:500
 Attack:1000
 Defence: 50
 Gold:100
 Identifier:0
 */
Boss::Boss(Psylc7Engine* pEngine,int ix, int iy,int id)
:MyDisplayableObject(pEngine, 2, 500, 1100, 50, 100, id)
{
    state = "green";
       m_iCurrentScreenX = ix;
       m_iCurrentScreenY= iy;
       m_iStartDrawPosX = -16;
       m_iStartDrawPosY = -16;
}
Boss::~Boss()
{
    
}

void Boss::virtDraw()
{
    if(!isVisible()){
           return;
       }
    monster_boss = m_pEngine->loadImage("./gameres/Monster/monster_king_"+state+".png",false);
    
      monster_boss.renderImageWithMask(getEngine()->getForegroundSurface(), 0, 0, m_iCurrentScreenX+m_iStartDrawPosX,m_iCurrentScreenY+m_iStartDrawPosY,32,32);
}
void Boss::virtDoUpdate(int iCurrentTime)
{
     currentTime = (SDL_GetTicks()/1000)%13;
      if(currentTime == 4){
         state = "indigo";
      }
    
      if(currentTime == 8){
         state = "pink";
      }
    if(currentTime == 12){
        state = "green";
    }
      
    
    
    
    /*
         int iTick = getEngine()->getModifiedTime()/100; // 1 per 100ms
         int iFrame = iTick%30;
         
         if(iFrame % 3 == 0) {
             state = "indigo";
         }
         
         if(iFrame % 3 == 1) {
             state = "pink";
   
         }
                
         if(iFrame % 3 == 2) {
             state = "green";
         }
         */
    return;
}

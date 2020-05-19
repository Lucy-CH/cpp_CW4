//
//  Character.cpp
//  SDL2_App
//
//  Created by Le Cheng on 27/04/2020.
//
#include "header.h"
#include "Character.hpp"
#include<math.h>
#include "CollisionDetection.h"
#include "Button.hpp"

#include <fstream>
#include <iostream>

/*
 Character should initiallu have
 life 1000
 attack 100
 defence 100
 gold 0
 identifier 0
 */
Character::Character(Psylc7Engine* pEngine,int ix,int iy, Psylc7TileManager* pTile)
    :MyDisplayableObject(pEngine,0,1000,100,100,0,0)
    ,pEngineMain(pEngine)
    ,key(0)
    ,sword(0)
    ,shield(0)

{
    this->Ptile = pTile;
    std:: cout << "Tile loaded at character"<< std::endl;

    hp = 1000;
    atk = 100;
    def = 100;
    gold = 0;
    
    iconx = 32;
    icony = 0;
    
    
    
    character = pEngine ->loadImage("./gameres/Character/Hero.png",false);
    m_iStartDrawPosX = -16;
    m_iStartDrawPosY = -16;
    
    m_iCurrentScreenX = ix;
    m_iCurrentScreenY = iy;
 

}

Character::~Character()
{
    
}
//Accessors
int Character::gethp(){return this->hp;}
int Character::getatk(){return this->atk;}
int Character::getdef()  {return this->def;}
int Character::getgold()  {return this->gold;}
int Character::getshield()  {return this->shield;}
int Character::getsword()  {return this->sword;}
//Modifiers
void Character::sethp(int iChange){this->hp += iChange;}
void Character::setatk(int iChange){this->atk += iChange;}
void Character::setdef(int iChange){this->def += iChange;}
void Character::setgold(int iChange){this->gold += iChange;}
void Character::setkey(int iChange){this->key += iChange;}
void Character::setX(int iChange){this->m_iCurrentScreenX = iChange;}
void Character::setY(int iChange){this->m_iCurrentScreenY = iChange;}
void Character::setshield(int iChange){this->shield = iChange;}
void Character::setsword(int iChange){this->sword = iChange;}

void Character::virtDraw()
{
    if(!isVisible()){
        return;
    }
    

    character.renderImageWithMask(getEngine()->getForegroundSurface(), iconx, icony, m_iCurrentScreenX+m_iStartDrawPosX, m_iCurrentScreenY+m_iStartDrawPosY, 32, 32);
}

void Character::virtDoUpdate(int iCurrentTime)
{

    if (!isVisible() || getEngine()->isPaused() )
        return;

    /*
     !!Here it comes the collision detection
     */
    
    // 1. Check and decide how the user will interact with the tiles
    // logic is, if the following tile is a wall, player shouldn't move
    // if it's a door, check if the player has at least a key, if not the player shouldn't move

    if (getEngine()->isKeyPressed(SDLK_UP))
    {
    
    if(!(Ptile->isWall(m_iCurrentScreenX+m_iStartDrawPosX, m_iCurrentScreenY+m_iStartDrawPosY)))
    {
   
            m_iCurrentScreenY -= 2;
            icony = 32*3;
            MoveBodyImage();
        

    }
    }
    
    if (getEngine()->isKeyPressed(SDLK_DOWN))
        
    {
    if(!(Ptile->isWall(m_iCurrentScreenX, m_iCurrentScreenY-m_iStartDrawPosY)))
    {
    
         m_iCurrentScreenY += 2;
         icony = 32*0;
         MoveBodyImage();
        
    }
     
    }
              
    if (getEngine()->isKeyPressed(SDLK_LEFT))
    {
        
      if(!(Ptile->isWall(m_iCurrentScreenX+m_iStartDrawPosX, m_iCurrentScreenY)))
       {
            m_iCurrentScreenX -= 2;
            icony = 32*1;
            MoveBodyImage();
        
        }
   }
        
    if (getEngine()->isKeyPressed(SDLK_RIGHT))
    {
        if(!(Ptile->isWall(m_iCurrentScreenX-m_iStartDrawPosX, m_iCurrentScreenY)))
          {
  
            m_iCurrentScreenX += 2;
         
            icony = 32*2;
            MoveBodyImage();
          }

    }
    
    //2. Check if the player has hit an object
    
    MyDisplayableObject* pObject;
    for ( int iObjectId = 0 ;
         (pObject = dynamic_cast<MyDisplayableObject*>(pEngineMain->getDisplayableObject( iObjectId ))
                ) != NULL ;
        iObjectId++ )
    {
        if ( pObject == this ) // This is us, skip it
            continue;
        if (pObject == nullptr) // Object does not exist, skip it
            continue;        // If you need to cast to the sub-class type, you must use dynamic_cast, see lecture 19
        
        if (CollisionDetection::checkRectangles(pObject->getXCentre() - 8, pObject->getXCentre() + 8,
                                                pObject->getYCentre() - 8, pObject->getYCentre() + 8,
                                                m_iCurrentScreenX - 16, m_iCurrentScreenX + 16,
                                                 m_iCurrentScreenY - 16, m_iCurrentScreenY + 16) )
        {
 
           //IF THE OBJECT HIT IS THE KEY!
            if(pObject->value ==1)
            {

                pEngineMain->removeDisplayableObject(pObject);
                pEngineMain->yellowkey1removed = true;
                std::cout<<"A key has been found"<< std:: endl;
                this->setkey(1);

            }
            //If THE OBJECT IS MONSTER
            
            if(pObject->value == 2 )
            {
                int demage;
                
                if(this->getshield() == 1)
                {
                    demage = (pObject->attack/2) - this->def;
                }
                
                if(this->getshield()!=1)
                {
                    demage = ( pObject->attack) - (this->def);
                }
                
                if( demage>= this->hp )
                {
                     pEngineMain->setState(pEngineMain->isDead());
                }else
                {   if(demage >0)
                    {
                    this->hp -= demage;
                    }
                    this->setgold(pObject->gold);
                    
                    pEngineMain->removeDisplayableObject(pObject);
                    pEngineMain->savegame(pObject->identifier);
                }
    
         
            }
           //IF THE OBJECT IS A STAIRCASE
            if(pObject->value == 3)
            {
               
            }
            
            //IF THE OBJECT IS A SHIELD
            if(pObject->value == 4)
            {
                this->shield = 1;
                pEngineMain->shieldremoved= true;
                pEngineMain->removeDisplayableObject(pObject);
            }
            //IF THE OBJECT IS A SWORD
            if(pObject->value == 5)
            {
                this->sword = 1;
                this->setatk(100);
                pEngineMain->swordremoved= true;
                pEngineMain->removeDisplayableObject(pObject);
             
            }
            //IF THE OBJECT IS A CHEST
            if(pObject->value == 6)
            {
                if(this->key >= 1)
                {
                    this->key -=1;
                    this->gold +=300;
                    pEngineMain->chestremoved= true;
                    pEngineMain->removeDisplayableObject(pObject);
                }else{return;}
            }
            //IF THE OBJECT IS A POTION
            if(pObject->value == 8)
            {
                this->hp +=200;
                pEngineMain->potionremoved= true;
                pEngineMain->removeDisplayableObject(pObject);
            }
              
             
        }
        
    }
    //3.The player cannot go into area that it's not supposed to be
      if (m_iCurrentScreenX < 16)
          m_iCurrentScreenX = 16;
      if (m_iCurrentScreenX >= 11*32 - m_iDrawWidth-16)
          m_iCurrentScreenX = 11*32 - m_iDrawWidth-16;
      if (m_iCurrentScreenY < 16)
          m_iCurrentScreenY = 16;
      if (m_iCurrentScreenY >= getEngine()->getWindowHeight() - m_iDrawHeight -16)
          m_iCurrentScreenY = getEngine()->getWindowHeight() - m_iDrawHeight -16;
    
   //4.Handle mouse input,player can also move character around using mouse
    

    

    this->redrawDisplay();
}

void Character::MouseDown(int iButton, int iX, int iY)
{
    std::cout<<iX<<","<<iY<<std::endl;
  
}

void Character::MoveBodyImage(){
    
     int iTick = getEngine()->getModifiedTime()/100; // 1 per 100ms
     int iFrame = iTick%30 +30;
     
     if(iFrame % 3 == 0) {
         iconx = 0;
     }
     
     if(iFrame % 3 == 1) {
         iconx = 32;
     }
            
     if(iFrame % 3 == 2) {
         iconx = 64;
     }
}



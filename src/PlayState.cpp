//
//  PlayState.cpp
//  SDL2_App
//
//  Created by Le Cheng on 17/04/2020.
//
#include "header.h"
#include "Psylc7Engine.hpp"
#include "Character.hpp"
#include "PlayState.hpp"
#include "Key.hpp"
#include "GreenSlime.hpp"
#include "Stairs.hpp"
#include <fstream>
#include <iostream>

PlayState::PlayState(Psylc7Engine* pEngine)
:State(pEngine)
,m_tile(pEngine)
,m_ipause(false)
{

}

PlayState::~PlayState()
{
    
}
void PlayState:: update()
{
    
}

void PlayState::SetUpBackgroundBuffer()
{
    engine->lockBackgroundForDrawing();
    engine->fillBackground(0xffffff);
    
    
    m_tile.setMapSize(11, 11);
    std::ifstream myfile("./gameres/Level1.txt");
    char array[121];
    if(!myfile.is_open())
    {std::cout<<"wrong"<< std::endl;}
    if(myfile.is_open()){
        std::cout<<"is open"<<std::endl;
    
        for(int x = 0; x < 121;x++){
            myfile>> array[x];
            std::cout<< array[x]<< std::endl;
        }
    }

    int z = 0;
    for ( int y = 0 ; y < 11 ; y++ )
    {
         for ( int x = 0 ; x < 11 ; x++ )
         {
               m_tile.setMapValue( x, y, array[z]-'a');
               z++;
         }
    }

  
    
    for ( int y = 0 ; y < 11 ; y++ )
    {
      for ( int x = 0 ; x < 11 ; x++ )
      std::cout << m_tile.getMapValue(x,y);
      std::cout << std::endl;
    }
    m_tile.setTopLeftPositionOnScreen( 0, 0 );
    m_tile.drawAllTiles( engine, engine->getBackgroundSurface() );
    
    engine->unlockBackgroundForDrawing();
    engine->redrawDisplay();
    
}

void PlayState::InitialiseObjects()
{
    engine->drawableObjectsChanged();
    /* Destroy the existing objects*/
    engine->destroyOldObjects(true);
    /* Create an object array*/
    engine->createObjectArray(5);
    
    
    yellowKey1 = new Key(engine, 160-16, 320-16);
    greenslime1 = new GreenSlime(engine,96-16, 32-16);
    stair = new Stairs(engine, 16,16);
    character = new Character(engine,192-16, 352-16,p_m_tile);
    engine->storeObjectInArray(3,character);
    engine->storeObjectInArray(1, yellowKey1);
    engine->storeObjectInArray(2, greenslime1);
    engine->storeObjectInArray(0, stair);
    
    engine->storeObjectInArray(4, NULL);
    engine->setAllObjectsVisible(true);
    
    
}
void PlayState::MouseDown(int iButton, int iX, int iY)
{
    
}
void PlayState::virtDrawStringsOnTop()
{  //draws the beige status box on screen and print its status

    //check it works :D
    int atk = character->getatk();
    int def = character->getdef();
    int hp = character->gethp();
    int gold = character->getgold();
    int key = character->getKeyNumber();
    //Print it out on screen
    char buf[128];
    char buf2[128];
    char buf3[128];
    char buf4[128];
    char buf5[128];
    
    sprintf(buf, "Attack: %d ",atk);
    engine->drawForegroundString(370, 230, buf, 0x000000, engine->getFont("Helvetica-Normal.ttf", 15));
    sprintf(buf2, "defence: %d ", def);
    engine->drawForegroundString(370, 230 + 30, buf2, 0x000000, engine->getFont("Helvetica-Normal.ttf", 15));
    sprintf(buf3, "hp: %d ",hp);
    engine->drawForegroundString(370, 230 +30 +30, buf3, 0x000000, engine->getFont("Helvetica-Normal.ttf", 15));
    sprintf(buf4, "gold: %d ",gold);
    engine->drawForegroundString(370, 230 +30 +30 +30, buf4, 0x000000, engine->getFont("Helvetica-Normal.ttf", 15));
    sprintf(buf5, "key: %d ",key);
    engine->drawForegroundString(370+150, 230 +30 +30 +30, buf5, 0x000000, engine->getFont("Helvetica-Normal.ttf", 15));
    
}
void PlayState:: virtKeyDown(int iKeyCode)
{
    switch (iKeyCode)
    {
    case SDLK_ESCAPE: // End program when escape is pressed
        engine->setExitWithCode(0);
        break;
    case SDLK_SPACE: // SPACE Pauses
        if (engine->BaseEngine::isPaused())
            engine->unpause();
        else
            engine->pause();
        break;
    }
}

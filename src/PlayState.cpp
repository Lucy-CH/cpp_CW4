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

PlayState::PlayState(Psylc7Engine* pEngine)
:State(pEngine)
,m_tile(pEngine)
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
    
    const char* data[] = {
        "bbbbbbbbbbb",
        "ccccccccccb",
        "bbbcbcbbbcb",
        "bbbcbcbbbcb",
        "ccccbcccccb",
        "bbbcbcbbbcb",
        "bbbcbcccccb",
        "ccccbbbbbbb",
        "bbbcccccccc",
        "bbbcbbbcbbb",
        "bbbcbbbcbbb"
        "bbbcbbbcbbb",

    };
    
    for ( int x = 0 ; x < 11 ; x++ )
    for ( int y = 0 ; y < 11 ; y++ )
    m_tile.setMapValue( x, y, data[y][x]-'a' );
    
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
    engine->createObjectArray(1);
    
    character = new Character(engine,192, 352);
    engine->storeObjectInArray(0,character);
    
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
    //Print it out on screen
    char buf[128];
    char buf2[128];
    char buf3[128];
    char buf4[128];
    
    sprintf(buf, "Attack: %d ",atk);
    engine->drawForegroundString(370, 230, buf, 0x000000, engine->getFont("Helvetica-Normal.ttf", 20));
    sprintf(buf2, "defence: %d ", def);
    engine->drawForegroundString(370, 230 + 30, buf2, 0x000000, engine->getFont("Helvetica-Normal.ttf", 20));
    sprintf(buf3, "hp: %d ",hp);
    engine->drawForegroundString(370, 230 +30 +30, buf3, 0x000000, engine->getFont("Helvetica-Normal.ttf", 20));
    sprintf(buf4, "gold: %d ",gold);
    engine->drawForegroundString(370, 230 +30 +30 +30, buf4, 0x000000, engine->getFont("Helvetica-Normal.ttf", 20));
    
    
   
    
    
}

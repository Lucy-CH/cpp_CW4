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
    
    //load tile value from file
    m_tile.setMapSize(11, 11);
    std::ifstream myfile("./gameres/Level1.txt");
    char array[121];
    if(!myfile.is_open())
    {std::cout<<"Level1 tile map file cannot be loaded"<< std::endl;}
    if(myfile.is_open()){
        std::cout<<"load level1 tile map"<<std::endl;
        for(int x = 0; x < 121;x++){
            myfile>> array[x];
        }
    }
    // set the values
    int z = 0;
    for ( int y = 0 ; y < 11 ; y++ )
    {
         for ( int x = 0 ; x < 11 ; x++ )
         {
               m_tile.setMapValue( x, y, array[z]-'a');
               z++;
         }
    }
    //print value on console for checking
    for ( int y = 0 ; y < 11 ; y++ )
    {
      for ( int x = 0 ; x < 11 ; x++ )
      std::cout << m_tile.getMapValue(x,y);
      std::cout << std::endl;
    }
    //rendering tiles
    
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
    
    if(engine->is_resumed)
    {
        std:: cout<< "is resumed"<<std::endl;
        loadgame();

    }
    
    
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
        savegame();
        engine->setState(engine->isPaused());
            engine->is_resumed = true;
        break;
    }
}
/*
 Game need to be saved before pausing
 */
void PlayState:: savegame()
{
    std:: ofstream saveFile;
    saveFile.open("saveData.txt");
    saveFile<< character->getCurrentX()<< std::endl;
    saveFile<< character->getCurrentY()<<std::endl;
    saveFile<< character->gethp()<< std::endl;
    saveFile<< character->getatk()<<std::endl;
    saveFile<< character->getdef()<<std::endl;
    saveFile<< character->getgold()<<std::endl;
    saveFile<< character->getKeyNumber()<<std::endl;
    saveFile.close();
}
void PlayState::loadgame()
{
    std::ifstream loadFile;
    loadFile.open("saveData.txt");
    int array[7];
    if(!loadFile.is_open())
    {std::cout<<"cannot find the save file"<< std::endl;}
    if(loadFile.is_open()){
        std::cout<<"load save file successfully"<<std::endl;
        for(int x = 0; x < 7;x++){
            loadFile>> array[x];
        }
    }
    character->setX(array[0]);
    character->setY(array[1]);
   
    
}

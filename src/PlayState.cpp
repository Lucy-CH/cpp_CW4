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
#include "FireBall.hpp"
#include "Boss.hpp"
#include "Sword.hpp"
#include "Shield.hpp"

#include <fstream>
#include <iostream>

PlayState::PlayState(Psylc7Engine* pEngine)
:State(pEngine)
,m_tile(pEngine)
,m_ipause(false)
,fire_visible(false)
,init(0)
,iconx(0)
,icony(0)

{
    image = pEngine->loadImage("./gameres/Backgrounds/playstate_background.png",true);
    snow = pEngine->loadImage("./gameres/Stuff/fireworks.png",true);
    

}

PlayState::~PlayState()
{
    
}
void PlayState:: update()
{
    
}

void PlayState::SetUpBackgroundBuffer()
{
    if(init == 0)
    {
    engine->lockBackgroundForDrawing();
    engine->fillBackground(0xffffff);
    
    //!1.load tile value from file
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
    //!2.set the values
    int z = 0;
    for ( int y = 0 ; y < 11 ; y++ )
    {
         for ( int x = 0 ; x < 11 ; x++ )
         {
               m_tile.setMapValue( x, y, array[z]-'a');
               z++;
         }
    }
    //!3.print value on console for checking
   /* for ( int y = 0 ; y < 11 ; y++ )
    {
      for ( int x = 0 ; x < 11 ; x++ )
      std::cout << m_tile.getMapValue(x,y);
      std::cout << std::endl;
    }
    */
    //!4.Rendering tiles
    m_tile.setTopLeftPositionOnScreen( 0, 0 );
    m_tile.drawAllTiles( engine, engine->getBackgroundSurface() );
    
    //!5.Background for score board

    im2 = ImageManager::get()->resizeTo(image, engine->getWindowWidth(), engine->getWindowHeight());
    im2.renderImage(engine->getBackgroundSurface(),0,0,352,0,image.getWidth(),image.getHeight());
    
    snow.renderImageWithMask(engine->getBackgroundSurface(), iconx, icony, 352+64*4,0, 64, 64);
        
    engine->unlockBackgroundForDrawing();
        
    init = 1;// if init is 1, it means tiles have been initialized and it doesn't have to be set again
    }
    //!Animated snow in the background
    if(init == 1)
    {  
        snow.renderImage(engine->getBackgroundSurface(), iconx, icony, 352+64*4,0, 64, 64);
    }
    
    engine->redrawDisplay();
    
}

void PlayState::InitialiseObjects()
{
    engine->drawableObjectsChanged();
    /* Destroy the existing objects*/
    engine->destroyOldObjects(true);
    /* Create an object array*/
    engine->createObjectArray(20);
    
    
    yellowKey1 = new Key(engine, 160-16, 320-16);
    greenslime1 = new GreenSlime(engine,96-16, 32-16,1);
    greenslime2 = new GreenSlime(engine,112,32-16,2);
    boss1 = new Boss(engine,45,32-16,3);//exit boss
    boss2 = new Boss(engine,10*32-16,10*32-16,4);//top
    boss3 = new Boss(engine,9*32-16,11*32-16,5);//botton left
    boss4 = new Boss(engine,11*32-16,11*32-16,6);//botton right
    
    stair = new Stairs(engine, 16,16);
    character = new Character(engine,192-16, 352-16,p_m_tile);
    fireball = new FireBall(engine, 192-32, 352-16,character);
    sword = new Sword(engine,45, 11*32-16);
    shield = new Shield(engine,8*32-16,3*32-16);
    
    engine->storeObjectInArray(0, stair);
    engine->storeObjectInArray(1, yellowKey1);
    engine->storeObjectInArray(2, greenslime1);
    engine->storeObjectInArray(3,fireball);
    engine->storeObjectInArray(4,greenslime2);
    engine->storeObjectInArray(5,boss1);
    engine->storeObjectInArray(6,boss2);
    engine->storeObjectInArray(7,boss3);
    engine->storeObjectInArray(8,boss4);
    engine->storeObjectInArray(9, sword);
    engine->storeObjectInArray(10, shield);
    engine->storeObjectInArray(18, character);
    engine->storeObjectInArray(19, NULL);
    
    if(engine->is_resumed)
    {
        std:: cout<< "is resumed"<<std::endl;
        loadgame();
        
        std::ifstream loadFile;
           loadFile.open("deletedobjects.txt");
           int i;
           if(!loadFile.is_open())
           {std::cout<<"cannot find the deletedobject file"<< std::endl;}
           if(loadFile.is_open()){
               std::cout<<"load deletedobject file successfully"<<std::endl;
               while(loadFile>>i){
                   switch(i)
                   {
                       case 1:
                           engine->removeDisplayableObject(greenslime1);
                           delete greenslime1;
                           break;
                       case 2:
                           engine->removeDisplayableObject(greenslime2);
                           delete greenslime2;
                           break;
                       case 3:
                           engine->removeDisplayableObject(boss1);
                           delete boss1;
                           break;
                       case 4:
                           engine->removeDisplayableObject(boss2);
                           delete boss2;
                           break;
                       case 5:
                           engine->removeDisplayableObject(boss3);
                           delete boss3;
                           break;
                       case 6:
                          engine->removeDisplayableObject(boss4);
                          delete boss4;
                          break;
 
                   }
               }
           }
        
        if(engine->yellowkey1removed){
            engine->removeDisplayableObject(yellowKey1);
            delete yellowKey1;
        }
        
        if(engine->shieldremoved){
            engine->removeDisplayableObject(shield);
            delete shield;
        }
        
        if(engine->swordremoved){
            engine->removeDisplayableObject(sword);
            delete sword;
        }
        
    
        
    }
    
    
    engine->setAllObjectsVisible(true);
    fireball->setVisible(false);
    
    
}
void PlayState::MouseDown(int iButton, int iX, int iY)
{
    if(!fire_visible)
    {
 
        fireball->setVisible(true);
        fire_visible = true;
    }
    
    else if(fire_visible){
        fireball->setVisible(false);
        fire_visible = false;
    }
    
   
}
void PlayState::virtDrawStringsOnTop()
{
    //draws the beige status box on screen and print its status
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
    engine->drawForegroundString(370, 230, buf, 0xffffff, engine->getFont("Helvetica-Normal.ttf", 15));
    sprintf(buf2, "defence: %d ", def);
    engine->drawForegroundString(370, 230 + 30, buf2, 0xffffff, engine->getFont("Helvetica-Normal.ttf", 15));
    sprintf(buf3, "hp: %d ",hp);
    engine->drawForegroundString(370, 230 +30 +30, buf3, 0xffffff, engine->getFont("Helvetica-Normal.ttf", 15));
    sprintf(buf4, "gold: %d ",gold);
    engine->drawForegroundString(370, 230 +30 +30 +30, buf4, 0xffffff, engine->getFont("Helvetica-Normal.ttf", 15));
    sprintf(buf5, "key: %d ",key);
    engine->drawForegroundString(370+150, 230 +30 +30 +30, buf5, 0xffffff, engine->getFont("Helvetica-Normal.ttf", 15));
    
    //!Important section:
    //!Draw narratives
    char intro1[128];
    char intro2[128];
    char intro3[128];
    char intro4[128];
    char intro5[128];
    char intro6[128];
    char intro7[128];
    char intro8[128];
    
    sprintf(intro1,  "You were dragged into this dungeon by");
    sprintf(intro2,  "accident.There are many dangerous");
    sprintf(intro3,  "monsters nesting in the darkness.if");
    sprintf(intro4,  "not careful you might end up dying in");
    sprintf(intro5,  "this place...");
    
    sprintf(intro6,  "The color changing monster looks intimidating,");
    sprintf(intro7,  "but maybe the treature in the ");
    sprintf(intro8,  "dungeon could lend you a hand...");
     
    
    engine->drawForegroundString(370, 50, intro1, 0xffffff, engine->getFont("Helvetica-Normal.ttf", 15));
       
    engine->drawForegroundString(370, 50+15, intro2, 0xffffff, engine->getFont("Helvetica-Normal.ttf", 15));
       
    engine->drawForegroundString(370, 50+15*2, intro3, 0xffffff, engine->getFont("Helvetica-Normal.ttf", 15));
       
    engine->drawForegroundString(370, 50+15*3, intro4, 0xffffff, engine->getFont("Helvetica-Normal.ttf", 15));
       
    engine->drawForegroundString(370, 50+15*4, intro5, 0xffffff, engine->getFont("Helvetica-Normal.ttf", 15));
    
    engine->drawForegroundString(370, 50+15*6, intro6, 0xffffff, engine->getFont("Helvetica-Normal.ttf", 15));
        
     engine->drawForegroundString(370, 50+15*7, intro7, 0xffffff, engine->getFont("Helvetica-Normal.ttf", 15));
        
     engine->drawForegroundString(370, 50+15*8, intro8, 0xffffff, engine->getFont("Helvetica-Normal.ttf", 15));
    
        
    


    
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
        init = 0;
        engine->setState(engine->isPaused());
            engine->is_resumed = true;
        break;
    }
}
/*
 Game need to be saved before pausing
 */
void PlayState::savegame()
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
    saveFile<< character->getsword()<<std::endl;
    saveFile<< character->getshield()<<std::endl;
    
    saveFile.close();
}
void PlayState::loadgame()
{
    std::ifstream loadFile;
    loadFile.open("saveData.txt");
    int array[9];
    if(!loadFile.is_open())
    {std::cout<<"cannot find the save file"<< std::endl;}
    if(loadFile.is_open()){
        std::cout<<"load save file successfully"<<std::endl;
        for(int x = 0; x < 9;x++){
            loadFile>> array[x];
        }
    }
    character->setX(array[0]);
    character->setY(array[1]);
    character->sethp(array[2]-character->gethp());
    character->setatk(array[3]-character->getatk());
    character->setdef(array[4]-character->getdef());
    character->setgold(array[5]- character->getgold());
    character->setkey(array[6]-character->getKeyNumber());
    character->setsword(array[7]);
    character->setshield(array[8]);
    
}

int PlayState::changeoffset()
{
      int iTick = engine->getModifiedTime()/100;
      int iFrame = iTick%16;
    
 
      if(iFrame % 9 == 1) {
             
          icony= 64*1;
          
      }
    
      if(iFrame % 9 == 2) {
            
         icony= 64*2;
     }
     if(iFrame % 9 == 3) {
           
        icony= 64*3;
     }
     if(iFrame % 9 == 4) {
           
        icony= 64*4;
    }
    
    if(iFrame % 9 == 5) {
           
        icony= 64*5;
    }
    if(iFrame % 9 == 6) {
           
        icony= 64*6;
    }
    if(iFrame % 9 == 7) {
           
        icony= 64*7;
    }
    if(iFrame % 9 == 8) {
           
        icony = 0;
    }

    this->SetUpBackgroundBuffer();
   
    return 0;
}


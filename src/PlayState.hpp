//
//  PlayState.hpp
//  SDL2_App
//
//  Created by Le Cheng on 17/04/2020.
//
#pragma once
#include "State.hpp"

#ifndef PlayState_hpp
#define PlayState_hpp

#include <stdio.h>
#include "Psylc7TileManager.hpp"
#endif /* PlayState_hpp */
class Character;
class Key;
class GreenSlime;
class Stairs;
class FireBall;
class Boss;
class Sword;
class Shield;
class Guardian;
class chest;

class PlayState:
    public State
{
public:
    PlayState(Psylc7Engine* pEngine);
    ~PlayState();
    void update();
    void SetUpBackgroundBuffer();
    void InitialiseObjects();
    void MouseDown(int iButton, int iX, int iY) ;
    void virtDrawStringsOnTop();
    void virtKeyDown(int iKeyCode);
    void savegame();
    void loadgame();
    //setters
    int changeoffset();


  
protected:
    Character* character;
    Psylc7TileManager m_tile;
    Psylc7TileManager* p_m_tile = &m_tile;
    Key* yellowKey1;
    GreenSlime* greenslime1;
    GreenSlime* greenslime2;
    Stairs* stair;
    FireBall* fireball;
    Boss* boss1;
    Boss* boss2;
    Boss* boss3;
    Boss* boss4;
    Guardian* guardian1;
    Guardian* guardian2;
    Guardian* guardian3;
    Guardian* guardian4;
    Sword* sword;
    Shield* shield;
    chest* chest1;
    
    SimpleImage image;
    SimpleImage im2;
    SimpleImage snow;
    
    bool m_ipause;
    bool fire_visible;
  
    int init;
    int iconx;
    int icony;

};


//
//  Psylc7Engine.hpp
//  SDL2_App
//
//  Created by Le Cheng on 15/04/2020.
//
#pragma once
#include "header.h"
#include "BaseEngine.h"


#ifndef Psylc7Engine_hpp
#define Psylc7Engine_hpp

#include <stdio.h>

#endif /* Psylc7Engine_hpp */

class State;// forward declaring classes instead of using headers
class MainState;
class PlayState;
class PauseState;
class DeathState;
class SuccessState;

class Psylc7Engine:
        public BaseEngine
{
public:
    bool is_resumed;
    bool yellowkey1removed;
    bool is_play_state;
    
    bool swordremoved ;
    bool shieldremoved ;
    bool chestremoved;
    bool potionremoved;
    
    Psylc7Engine();
    ~Psylc7Engine();
    void virtSetupBackgroundBuffer();
    int virtInitialiseObjects();
    void virtMouseDown(int iButton,int iX, int iY);
    void virtKeyDown(int iKeyCode);
    void setState(State* state);
    State* isPlaying();
    State* isPaused();
    State* isDead();
    State* isSuccessed();
    void virtDrawStringsOnTop();
    void virtMainLoopDoBeforeUpdate();
    void savegame(int id);
    

    

protected:
    State* currentState;
    MainState* menu;
    PlayState* play;
    PauseState* pausestate;
    DeathState* death;
    SuccessState* success;

};

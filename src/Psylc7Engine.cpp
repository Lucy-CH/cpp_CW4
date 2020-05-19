//
//  Psylc7Engine.cpp
//  SDL2_App
//
//  Created by Le Cheng on 15/04/2020.
//
#include "header.h"
#include "Psylc7Engine.hpp"
#include "MainState.hpp"
#include "PlayState.hpp"
#include "PauseState.hpp"
#include "DeathState.hpp"
#include "SuccessState.hpp"

#include <fstream>
#include <iostream>

Psylc7Engine::Psylc7Engine()


{
    
    //!deletedobjects.txt stores list of objects that should have been destroyed, this
    //!line of code ensure that this file is cleared every time the game restarts
    
    if( remove( "deletedobjects.txt" ) != 0 )
      perror( "Error deleting file" );
    else
      puts( "File successfully deleted" );
    
    //!All states are initialized here
    //!but only the state that the currentstate is pointing is showned
    
    menu = new MainState(this);
    play = new PlayState(this);
    pausestate= new PauseState(this);
    death = new DeathState(this);
    success = new SuccessState(this);
    currentState = menu;
    
    is_play_state = false;
    is_resumed = false;
    yellowkey1removed = false;
   
    swordremoved = false;
    shieldremoved = false;
    chestremoved = false;
}

Psylc7Engine::~Psylc7Engine()
{
    
}

void Psylc7Engine::virtSetupBackgroundBuffer()
{
    
    currentState->SetUpBackgroundBuffer();
}

void Psylc7Engine::virtMouseDown(int iButton,int iX, int iY)
{
    currentState->MouseDown(iButton, iX, iY);
}
                 
int Psylc7Engine::virtInitialiseObjects()
{
    currentState->InitialiseObjects();
    
    return 0;
}

void Psylc7Engine::virtKeyDown(int iKeyCode)
{
    currentState->virtKeyDown(iKeyCode);
}
void Psylc7Engine::setState(State *state)
{
    this->currentState = state;
    this->virtSetupBackgroundBuffer();
    this->virtInitialiseObjects();

}

State* Psylc7Engine::isPlaying()
{
    is_play_state = true;
    return play;

}
State* Psylc7Engine::isPaused()
{
    is_play_state = false;
    return pausestate;
}

State* Psylc7Engine::isDead()
{
    is_play_state = false;
    return death;
}
State* Psylc7Engine::isSuccessed()
{
    is_play_state = false;
    return success;
}
void Psylc7Engine::virtDrawStringsOnTop()
{

    currentState->virtDrawStringsOnTop();
}

void Psylc7Engine::virtMainLoopDoBeforeUpdate()
{
   if(is_play_state)
   {
       
       currentState->changeoffset();
       
       return;
   }
    
   return;
}
void Psylc7Engine::savegame(int id)
{
    std:: ofstream saveFile;
    saveFile.open("deletedobjects.txt",std::ios_base::app);
    saveFile<< id<< std::endl;
  
    saveFile.close();
}


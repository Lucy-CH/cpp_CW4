//
//  PauseState.hpp
//  SDL2_App
//
//  Created by Le Cheng on 07/05/2020.
//
#include "State.hpp"
#include "Psylc7Engine.hpp"
#ifndef PauseState_hpp
#define PauseState_hpp

#include <stdio.h>

#endif /* PauseState_hpp */

class PauseState
: public State
{
public:
    PauseState(Psylc7Engine* pEngine);
    ~PauseState();
 void SetUpBackgroundBuffer();
 void virtDrawStringsOnTop();
 void virtKeyDown(int iKeyCode);
 void InitialiseObjects();
 void update();
void MouseDown(int iButton, int iX, int iY);
    
 
protected:
    
    
};

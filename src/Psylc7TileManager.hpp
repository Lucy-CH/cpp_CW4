//
//  Psylc7TileManager.hpp
//  SDL2_App
//
//  Created by Le Cheng on 30/04/2020.
//
#pragma once
#ifndef Psylc7TileManager_hpp
#define Psylc7TileManager_hpp

#include "TileManager.h"
#include "Psylc7Engine.hpp"
#include <stdio.h>

#endif /* Psylc7TileManager_hpp */

class Psylc7TileManager:
    public TileManager
{
 public:
    Psylc7TileManager(Psylc7Engine *pEngine);
    ~Psylc7TileManager();
    
    void drawSomeTiles(Psylc7Engine * pEngine, DrawingSurface* pSurface, int iMapXStart, int iMapYStart, int iWidth, int iHeight ) const;
    
    void drawAllTiles(Psylc7Engine* pEngine, DrawingSurface* pSurface) const;
    
    void virtDrawTileAt(
        Psylc7Engine* pEngine,
        DrawingSurface* pSurface,
        int iMapX, int iMapY,
        int iStartPositionScreenX, int iStartPositionScreenY ) const ;
        
    bool isWall(int iScreenX, int iScreenY);

 protected:
    SimpleImage floor;
    SimpleImage wall;
    SimpleImage yellow_door;
};

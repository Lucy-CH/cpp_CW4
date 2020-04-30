//
//  Psylc7TileManager.cpp
//  SDL2_App
//
//  Created by Le Cheng on 30/04/2020.
//
#include "header.h"
#include "Psylc7TileManager.hpp"
#include "ImageManager.h"

Psylc7TileManager::Psylc7TileManager(Psylc7Engine* pEngine)
                :TileManager(32, 32)
{
    floor = pEngine->loadImage("./gameres/Brick_Wall/marbletile.png",false);
    
     wall = pEngine->loadImage("./gameres/Brick_Wall/wallside.png",false);
    
}

Psylc7TileManager::~Psylc7TileManager()
{
    
}

void Psylc7TileManager::virtDrawTileAt(Psylc7Engine *pEngine, DrawingSurface *pSurface, int iMapX, int iMapY, int iStartPositionScreenX, int iStartPositionScreenY) const
{
    
}

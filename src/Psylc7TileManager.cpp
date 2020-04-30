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
    wall = pEngine->loadImage("./gameres/Brick_Wall/marbletile.png",false);
    
     floor = pEngine->loadImage("./gameres/Brick_Wall/wallside.png",false);
    
}



Psylc7TileManager::~Psylc7TileManager()
{
    
}
void Psylc7TileManager::drawAllTiles(Psylc7Engine* pEngine, DrawingSurface* pSurface) const
{
    pSurface->mySDLLockSurface();
    for (int iTX = 0; iTX < m_iMapWidth; iTX++)
        for (int iTY = 0; iTY < m_iMapHeight; iTY++)
        {
            this->virtDrawTileAt(pEngine, pSurface,
                iTX, iTY,
                m_iBaseScreenX + getTileWidth()*iTX,
                m_iBaseScreenY + getTileHeight()*iTY );
        }
    pSurface->mySDLUnlockSurface();
}

void Psylc7TileManager::drawSomeTiles(Psylc7Engine * pEngine, DrawingSurface* pSurface, int iMapXStart, int iMapYStart, int iWidth, int iHeight ) const
{
    pSurface->mySDLLockSurface();
    for (int iTX = 0; iTX < iWidth; iTX++)
        for (int iTY = 0; iTY < iHeight; iTY++)
        {
            this->virtDrawTileAt(pEngine, pSurface,
                iTX + iMapXStart, iTY + iMapYStart,
                m_iBaseScreenX + getTileWidth()*iTX,
                m_iBaseScreenY + getTileHeight()*iTY);
        }
    pSurface->mySDLUnlockSurface();
}

void Psylc7TileManager::virtDrawTileAt(Psylc7Engine *pEngine, DrawingSurface *pSurface, int iMapX, int iMapY, int iStartPositionScreenX, int iStartPositionScreenY) const
{
    
switch(getMapValue(iMapX, iMapY))
{   //This is actually the wall
    case 1:
    wall.renderImageWithMask(pEngine->getBackgroundSurface(), 0, 0, iStartPositionScreenX, iStartPositionScreenY, wall.getWidth(), wall.getHeight());
       break;
    //And this is the floor
    case 2:
    floor.renderImageWithMask(pEngine->getBackgroundSurface(), 0, 0, iStartPositionScreenX, iStartPositionScreenY, wall.getWidth(), wall.getHeight());
        break;
 
    
}
     
}

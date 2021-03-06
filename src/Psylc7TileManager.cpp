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
    
    tile1 = pEngine->loadImage("./gameres/Brick_Wall/tile1.png",false);
    tile2 = pEngine->loadImage("./gameres/Brick_Wall/tile2.png",false);
    tile3 = pEngine->loadImage("./gameres/Brick_Wall/tile3.png",false);
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
{
    case 1:
    floor.renderImageWithMask(pEngine->getBackgroundSurface(), 0, 0, iStartPositionScreenX, iStartPositionScreenY, wall.getWidth(), wall.getHeight());
       break;

    case 2:
    wall.renderImageWithMask(pEngine->getBackgroundSurface(), 0, 0, iStartPositionScreenX, iStartPositionScreenY, wall.getWidth(), wall.getHeight());

    break;
        
    case 3:
    tile1.renderImageWithMask(pEngine->getBackgroundSurface(), 0, 0, iStartPositionScreenX, iStartPositionScreenY, wall.getWidth(), wall.getHeight());
    break;
        
    case 4:
       tile2.renderImageWithMask(pEngine->getBackgroundSurface(), 0, 0, iStartPositionScreenX, iStartPositionScreenY, wall.getWidth(), wall.getHeight());
       break;
        
    case 5:
       tile3.renderImageWithMask(pEngine->getBackgroundSurface(), 0, 0, iStartPositionScreenX, iStartPositionScreenY, wall.getWidth(), wall.getHeight());
       break;
    
 
     
}
     
}

bool Psylc7TileManager::isWall(int iScreenX, int iScreenY)
{
    int iX = getMapXForScreenX(iScreenX);
    int iY = getMapYForScreenY(iScreenY);
    int tile =getMapValue(iX, iY);
    if(tile == 2){return true;}
    else{return false;}
   
}


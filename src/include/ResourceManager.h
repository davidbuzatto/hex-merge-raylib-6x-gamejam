/**
 * @file ResourceManager.h
 * @author Prof. Dr. David Buzatto
 * @brief ResourceManager struct and function declarations.
 * 
 * @copyright Copyright (c) 2026
 */
#pragma once

#include "raylib/raylib.h"

#include "SoundPool.h"

typedef struct ResourceManager {

    Font font;

    Texture2D startScreenTexture;
    Texture2D gameOverScreenTexture;

    Texture2D helpPage01Texture;
    Texture2D helpPage02Texture;
    Texture2D helpPage03Texture;
    Texture2D helpPage04Texture;

    SoundPool *placeSoundPool;
    SoundPool *placeFailSoundPool;
    SoundPool *mergeSoundPool;
    SoundPool *specialHexSoundPool;
    SoundPool *explodingSoundPool;
    SoundPool *showingSoundPool;

    Sound gameOverSound;

    Music bgMusic;
    
} ResourceManager;

// Read-only outside this module. Use rm->field to access resources.
extern const ResourceManager * const rm;

/**
 * @brief Load global game resources, linking them in the global instance of
 * ResourceManager called rm.
 */
void loadResourcesResourceManager( void );

/**
 * @brief Unload global game resources.
 */
void unloadResourcesResourceManager( void );
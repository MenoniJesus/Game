#include "SoundManager.h"
#include <SDL2/SDL.h>
#include <iostream>

SoundManager* SoundManager::s_Instance = nullptr;

bool SoundManager::Init(int freq, Uint16 format, int channels, int chunksize) {
    if (Mix_OpenAudio(freq, format, channels, chunksize) == -1) {
        SDL_Log("Mix_OpenAudio Error: %s", Mix_GetError());
        return false;
    }
    return true;
}

void SoundManager::Clean() {
    if (m_Music) {
        Mix_FreeMusic(m_Music);
    }
    for (auto& pair : m_SoundEffects) {
        Mix_FreeChunk(pair.second);
    }
    Mix_CloseAudio();
}

void SoundManager::StartMusic(const std::string& filePath, int loops) {
    m_Music = Mix_LoadMUS(filePath.c_str());
    if (!m_Music) {
        SDL_Log("Mix_LoadMUS Error: %s", Mix_GetError());
        return;
    }
    if (Mix_PlayMusic(m_Music, loops) == -1) {
        SDL_Log("Mix_PlayMusic Error: %s", Mix_GetError());
        Mix_FreeMusic(m_Music);
        m_Music = nullptr;
    }
}

void SoundManager::StopMusic() {
    Mix_HaltMusic();
    if (m_Music) {
        Mix_FreeMusic(m_Music);
        m_Music = nullptr;
    }
}

void SoundManager::PlaySoundEffect(const std::string& filePath, int loops) {
    Mix_Chunk* chunk = nullptr;
    if (m_SoundEffects.find(filePath) == m_SoundEffects.end()) {
        chunk = Mix_LoadWAV(filePath.c_str());
        if (!chunk) {
            SDL_Log("Mix_LoadWAV Error: %s", Mix_GetError());
            return;
        }
        m_SoundEffects[filePath] = chunk;
    } else {
        chunk = m_SoundEffects[filePath];
    }
    Mix_PlayChannel(-1, chunk, loops);
}
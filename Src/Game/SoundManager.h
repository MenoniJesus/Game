#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include <SDL2/SDL_mixer.h>
#include <string>
#include <map>

class SoundManager {
public:
    static SoundManager* GetInstance() {
        return s_Instance = (s_Instance != nullptr) ? s_Instance : new SoundManager();
    }

    bool Init(int freq = 22050, Uint16 format = AUDIO_S16SYS, int channels = 2, int chunksize = 4096);
    void Clean();

    void StartMusic(const std::string& filePath, int loops = -1);
    void StopMusic();
    void PlaySoundEffect(const std::string& filePath, int loops = 0);

private:
    SoundManager() {}
    ~SoundManager() {}

    static SoundManager* s_Instance;
    Mix_Music* m_Music;
    std::map<std::string, Mix_Chunk*> m_SoundEffects;
};

#endif // SOUNDMANAGER_H
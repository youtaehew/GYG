#include "Sound.h"

void Sound::playSound(const char* soundFile) {
    PlaySoundA(soundFile, NULL, SND_FILENAME | SND_ASYNC);
}

#include "flappy_engine/Sound.h"

void flappy_engine::Sound::PlaySound(const char* file_name)
{
	if (sound.openFromFile(file_name))
	{
		sound.play();
		return;
	}
}

void flappy_engine::Sound::SetVolume(float volume)
{
	sound.setVolume(volume);
}
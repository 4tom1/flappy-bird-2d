#include <iostream>

#include "Sound.h"

void flappy_engine::Sound::PlaySound(const char* file_name)
{
	if (sound.openFromFile(file_name))
	{
		sound.play();
		return;
	}

	std::cout << "Error: Cannot open a file." << std::endl;
}

void flappy_engine::Sound::SetVolume(float volume)
{
	sound.setVolume(volume);
}
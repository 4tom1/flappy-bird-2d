#include <iostream>

#include "Sound.h"

void flappy_engine::Sound::PlaySound(const char* file_name)
{
	if (!music.openFromFile(file_name))
	{
		std::cout << "Error: Cannot open a file." << std::endl;
		std::getchar();

		return;
	}
		
	music.play();
}

void flappy_engine::Sound::SetVolume(float volume)
{
	music.setVolume(volume);
}
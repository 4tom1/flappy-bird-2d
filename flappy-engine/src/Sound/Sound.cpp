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

	std::cout << "Success." << std::endl;
	std::getchar();
}

void flappy_engine::Sound::SetVolume(float volume)
{
	music.setVolume(volume);
}
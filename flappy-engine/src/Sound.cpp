#include <iostream>

#include "flappy_engine/Sound.h"

void flappy_engine::Sound::PlaySound(const char* file_path)
{
	if (sound.openFromFile(file_path))
	{
		sound.play();
		return;
	}

	std::cout << "Error: cannot open a file " << file_path << ";" << std::endl;
	getchar();
}

void flappy_engine::Sound::SetVolume(float volume)
{
	sound.setVolume(volume);
}
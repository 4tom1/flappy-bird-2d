#include <iostream>

#include <flappy-engine/Sound.h>

int main()
{
	flappy_engine::Sound sound;

	float vol;
	std::cin >> vol;

	sound.SetVolume(vol);
	sound.PlaySound("assets/sounds/endofline.mp3");
	
	while (1);

	return 0;
}
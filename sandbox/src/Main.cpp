#include <flappy-engine/Sound.h>

int main()
{
	flappy_engine::Sound sound;
	sound.PlaySound("assets/sounds/audio_hit.wav");
	sound.PlaySound("assets/sounds/endofline.mp3");

	return 0;
}
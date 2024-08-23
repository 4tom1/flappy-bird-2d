#include <iostream>

#include "flappy_engine/GameObjComponents/Animator.h"

unsigned int flappy_engine::Animator::frame_rate = 0;

void flappy_engine::Animator::Create(const char* file_paths[textures_limit], unsigned int frame_per_sec)
{
	animation_frame_rate = frame_per_sec;
	
	for (size_t i = 0; i < textures_limit; i++)
	{
		if (!textures[i].loadFromFile(file_paths[i]))
		{
			std::cout << "Error: cannot open a file " << file_paths[i] << ";" << std::endl;
			std::getchar();
		}
	}
}

void flappy_engine::Animator::Play()
{
	play = true;
}

void flappy_engine::Animator::Stop()
{
	play = false;
	game_obj_sprite->DefaultTex();
}

void flappy_engine::Animator::Update()
{
	if (animation_frame_rate != 0 && play)
	{
		loop++;

		if (loop >= frame_rate / animation_frame_rate)
		{
			game_obj_sprite->setTexture(textures[++current_frame % textures_limit]);

			loop = 0;
		}
	}
}

void flappy_engine::Animator::SetFrameRate(unsigned int frame_rate)
{
	Animator::frame_rate = frame_rate;
}
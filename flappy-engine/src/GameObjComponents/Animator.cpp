#include "flappy_engine/GameObjComponents/Animator.h"

#include <iostream>

unsigned int flappy_engine::Animator::frame_rate = 0; 

void flappy_engine::Animator::Animation(const char* file_paths[uint_textures], unsigned int frame_per_sec)
{
	animation_frame_rate = frame_per_sec;
	
	for (size_t i = 0; i < uint_textures; i++)
	{
		if (!textures[i].loadFromFile(file_paths[i])) // <- Loading all textures from files paths.
		{
			std::cout << "Error: cannot open a file " << file_paths[i] << ";" << std::endl;
			std::getchar();
		}

		// If load of any fail, prints error in console and wait by getchar.
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

	// Stops animation and sets default texture of sprite.
}

void flappy_engine::Animator::Update()
{
	if (animation_frame_rate != 0 && play)
	{
		loop++; // Frame counter.

		if (loop >= frame_rate / animation_frame_rate) // Change texture if 
		{
			game_obj_sprite->setTexture(textures[++current_frame % uint_textures]);

			loop = 0;
		}
	}
}

void flappy_engine::Animator::SetFrameRate(unsigned int frame_rate)
{
	Animator::frame_rate = frame_rate;
}
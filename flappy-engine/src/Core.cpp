#include <iostream>

#include "flappy_engine/Core.h"

flappy_engine::Engine* flappy_engine::InitEngine(unsigned int width, unsigned int high, unsigned int frame_rate, const char* window_name, float volume)
{
	return new Engine(width, high, frame_rate, window_name, volume);
}

flappy_engine::Engine::Engine(unsigned int width, unsigned int high, unsigned int frame_rate, const char* window_name, float volume) 
	: window(width, high, window_name, frame_rate)
{
	GameObj::SetGameObjManager(&game_obj_manager);
	input.SetWindow(&window);
	sound.SetVolume(volume);
}

void flappy_engine::Engine::UpdateAll()
{
	game_obj_manager.UpdateAllObj();
	window.Update();
}

void flappy_engine::Engine::RenderAll()
{
	window.clear();
	
	for (size_t i = 0; i < game_obj_manager.Size(); i++)
	{
		if (game_obj_manager[i]->sprite) window.draw(*(game_obj_manager[i]->sprite));
	}
	
	window.display();
}

void flappy_engine::Engine::DeleteAllObj()
{
	game_obj_manager.DeleteAllObj();
}
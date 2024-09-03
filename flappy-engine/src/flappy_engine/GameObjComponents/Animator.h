#ifndef _FLAPPY_ENGINE_ANIMATOR_
#define _FLAPPY_ENGINE_ANIMATOR_

#include <flappy_engine/GameObjComponents/Sprite.h>

namespace flappy_engine {
	
	constexpr unsigned int uint_textures = 4;
	// uint_textures is number of load textures and is parameter of how many frames animation has.
	// Is simplify for flappy bird game, because bird in game has only 4 frames of animation.

	class Animator // Animator handle animation system. It's part of component system. 
	// (Unfortunetly for this project only, because it was prepered for flappy bird game.)
	{
		public:
			
			Animator(Sprite* game_obj_sprite) : game_obj_sprite(game_obj_sprite) {}
			// Default costructor for initializing sprite pointer. 

			void Animation(const char* file_paths[uint_textures], unsigned int frame_per_sec);
			// Animation method create animation by file paths and set animation speed.

			void Play();
			// Play, plays animation.

			void Stop();
			// Stop, stops animation.

		private:

			void Update();
			// Update in animator case update animation every anim. frame rate by set next texture in vector.

			static void SetFrameRate(unsigned int frame_rate);
			// SetFrameRate, sets window frame rate in engine initialization.
			
			flappy_engine::Sprite* game_obj_sprite;
			// Sprite pointer is initializing in constructor and is pointing on game object's sprite to change textures while animation.

			sf::Texture textures[uint_textures];
			// All loaded textures. Loaded from files in Animation method.

			bool play = true;
			// Play state. It means that animation is playing or not.

			unsigned int current_frame = 0;
			// current_frame marked on which frame of animation, animator is.

			unsigned int animation_frame_rate = 0;
			// Animation frame speed per sec.

			unsigned int loop = 0;
			// loop is increment every Update call. (Nothing bad happen if it looped.)

			static unsigned int frame_rate;
			// Window frame rate.

			friend class GameObjManager;
			friend class Engine;

			// Friendships for hide non-api parts of engine. (It's only for visuals in this project.)
	};
}

#endif
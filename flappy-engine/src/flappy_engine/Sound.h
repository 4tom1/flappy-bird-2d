#ifndef _FLAPPY_ENGINE_SOUND_
#define _FLAPPY_ENGINE_SOUND_

#include <SFML/Audio.hpp>

namespace flappy_engine {

	class Sound // Handle sound.
	{
		public:

			void PlaySound(const char* file_path);
			// Plays sound from file.

			void SetVolume(float volume);
			// Sets volume. The volume is a value between 0 (mute) and 100 (full volume).

		private:
			
			sf::Music sound;
			// SFML Music class object to handle sound.
	};
}

#endif
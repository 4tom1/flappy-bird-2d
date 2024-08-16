#ifndef _FLAPPY_ENGINE_SOUND_
#define _FLAPPY_ENGINE_SOUND_

#include <SFML/Audio.hpp>

namespace flappy_engine {

	class Sound
	{
		public:

			void PlaySound(const char* file_path);
			void SetVolume(float volume);

		private:
			
			sf::Music sound;
	};
}

#endif
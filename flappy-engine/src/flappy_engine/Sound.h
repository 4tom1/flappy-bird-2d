#ifndef _FLAPPY_ENGINE_SOUND_
#define _FLAPPY_ENGINE_SOUND_

#include <SFML/Audio.hpp>

namespace flappy_engine {

	class Sound
	{
		public:

			void PlaySound(const char*);
			void SetVolume(float);

		private:
			
			sf::Music sound;
	};
}

#endif
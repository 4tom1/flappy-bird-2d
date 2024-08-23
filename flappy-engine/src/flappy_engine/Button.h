#ifndef _FLAPPY_ENGINE_BUTTON_
#define _FLAPPY_ENGINE_BUTTON_

#include <flappy_engine/GameObj.h>

namespace flappy_engine {

	class Button : public GameObj
	{
		typedef Scale Size;
	
		public:

			void SetSize(float x, float y);

			inline bool IsPressed() const { return is_pressed; }
			void Update();

		private:

			bool is_pressed = false;
			Size size;
	};
}

#endif
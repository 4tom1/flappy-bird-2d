#ifndef _FLAPPY_ENGINE_BUTTON_
#define _FLAPPY_ENGINE_BUTTON_

#include <flappy_engine/GameObj.h>

namespace flappy_engine {

	class Button : public GameObj // Button class is special game object with override virtual update.
	{
		public:

			void SetSize(float x, float y);
			// SetSize sets size of button. X is width, Y is hight.

			inline bool IsPressed() const { return is_pressed; }
			// It answer on philosophical question: "Is pressed? Or it isn't?".

		private:

			void Update() override;
			// Update, checks pressed state and updates is_pressed variable.

			bool is_pressed = false;
			// Button state.

			float x = 0, y = 0;
			// Size in x and y.
	};
}

#endif
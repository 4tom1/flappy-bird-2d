#ifndef _RESTARTBUTTON_
#define _RESTARTBUTTON_

#include <flappy_engine/Button.h>

namespace flappy_bird {

	class RestartButton : public flappy_engine::Button
	{
		public:
			
			RestartButton();

			void Hide();
			void Show();
	};
}

#endif
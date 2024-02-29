#ifndef __CPPSDLRECT__
#define __CPPSDLRECT__
#include <SDL_rect.h>

namespace SDL {
	struct Rect {
		float x, y, w, h;

		SDL_Rect GetSDLRect() {
			SDL_Rect ret = { static_cast<int>(x),  static_cast<int>(y),  static_cast<int>(w),  static_cast<int>(h) };
			return ret;
		}

		SDL_FRect GetSDLFRect() {
			SDL_FRect ret = { x, y, w, h };
			return ret;
		}
	};
}

#endif
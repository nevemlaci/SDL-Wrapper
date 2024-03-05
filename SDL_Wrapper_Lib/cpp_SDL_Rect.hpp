#ifndef __CPPSDLRECT__
#define __CPPSDLRECT__
#include <SDL_rect.h>

namespace SDL {
	/// @brief Rectangle structure
	struct Rect {

		float x, y, w, h;

		/// @brief converts an SDL::Rect into an SDL_Rect
		/// @return returns the SDL_Rect
		SDL_Rect GetSDLRect() {
			SDL_Rect ret = { static_cast<int>(x),  static_cast<int>(y),  static_cast<int>(w),  static_cast<int>(h) };
			return ret;
		}

		/// @brief converts an SDL::Rect into an SDL_FRect
		/// @return returns the SDL_FRect
		SDL_FRect GetSDLFRect() {
			SDL_FRect ret = { x, y, w, h };
			return ret;
		}

		Rect operator=(const Rect& other) {
			this->x = other.x;
			this->y = other.y;
			this->w = other.w;
			this->h = other.h;

			return (*this);
		}
	};
}

#endif
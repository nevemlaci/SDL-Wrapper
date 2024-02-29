#ifndef __CPPSDLWINDOW__
#define __CPPSDLWINDOW__
#include <SDL.h>

namespace SDL {
	class Window {
	public:
		Window(const char* title, size_t x, size_t y, size_t w, size_t h, Uint32 flags);
		
	private:
		SDL_Window* sdlwindow;
		
	};
}

#endif
#include "cpp_SDL_Window.hpp"

namespace SDL {
	Window::Window(const char* title, size_t x , size_t y , size_t w , size_t h , Uint32 flags) 
		: sdlwindow(SDL_CreateWindow(title, x, y, w, h, flags))
	{}
}
#include "cpp_SDL_Window.hpp"

namespace SDL {
	Window::Window(const char* title, int x , int y , int w , int h , Uint32 flags) 
		: sdlwindow(SDL_CreateWindow(title, x, y, w, h, flags))
	{}

	Window::~Window() {
		SDL_DestroyWindow(this->sdlwindow);
	}

	void Window::HideWindow() {
		SDL_HideWindow(this->sdlwindow);
	}

	void Window::ShowWindow() {
		SDL_ShowWindow(this->sdlwindow);
	}

	SDL_Window* Window::GetWindow() const {
		return this->sdlwindow;
	}
}
#include "cpp_SDL_Window.hpp"

namespace SDL {
	Window::Window(const char* title, int x , int y , int w , int h , Uint32 flags) 
		: m_SDLWindow(SDL_CreateWindow(title, x, y, w, h, flags))
	{
		if (!m_SDLWindow) {
			throw SDL_GetError();
		}
	}

	Window::~Window() {
		SDL_DestroyWindow(this->m_SDLWindow);
	}

	void Window::HideWindow() {
		SDL_HideWindow(this->m_SDLWindow);
	}
	
	void Window::ShowWindow() {
		SDL_ShowWindow(this->m_SDLWindow);
	}

	SDL_Window* Window::GetWindow() const {
		return this->m_SDLWindow;
	}
}
#include "cpp_SDL.hpp"
#include <iostream>

namespace SDL {
	SDL::SDL() : sdlinit(SDL_Init(SDL_INIT_EVERYTHING)), event(SDL_Event()) {
		if (sdlinit != 0) {
			std::cout << "ERROR: Failed to initialize SDL. SDLInit value: " << sdlinit << "\t\nSDL Error :" << SDL_GetError() << '\n';
		}
	};

	SDL& SDL::Get() { 
		static SDL instance;
		return instance; 
	}

	int SDL::PollEvents() {
		return SDL_PollEvent(&(this->event));
	}

	SDL_Event SDL::GetEvent() const {
		return this->event;
	}
}


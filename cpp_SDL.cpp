#include "cpp_SDL.h"
#include <iostream>

namespace SDL {
	SDL::SDL() : sdlinit(SDL_Init(SDL_INIT_EVERYTHING)) {
		if (sdlinit != 0) {
			std::cout << "ERROR: Failed to initialize SDL. SDLInit value: " << sdlinit << "\t\nSDL Error :" << SDL_GetError() << '\n';
		}
	};

	SDL& SDL::Get() { 
		static SDL instance;
		return instance; 
	}

	void SDL::PollEvents() {
		SDL_PollEvent(&(this->event));
	}
}


#include "cpp_SDL.hpp"
#include <iostream>

namespace SDL {
	SDL::SDL() : sdlinit(SDL_Init(SDL_INIT_EVERYTHING)), event(SDL_Event()) {
		if (sdlinit != 0) {
			throw SDL_GetError();
		}
	};

	SDL& SDL::Get() { 
		static SDL instance;
		return instance; 
	}

	int SDL::PollEvents() {
		return SDL_PollEvent(&(this->event));
	}

	const SDL_Event& SDL::GetEvent() {
		return this->event;
	}

	bool SDL::CheckKey(SDL_Scancode key) {
		return this->keyStates[key];
	}

	bool SDL::CheckKey(const char* key) {
		return this->keyStates[SDL_GetScancodeFromName(key)];
	}
}


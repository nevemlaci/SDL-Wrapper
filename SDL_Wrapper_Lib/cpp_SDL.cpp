#include "cpp_SDL.hpp"
#include <iostream>
#include <SDL_ttf.h>

namespace SDL {
	SDL::SDL() 
		: 
		m_SDLInit(SDL_Init(SDL_INIT_EVERYTHING)), m_SDLEvent(SDL_Event()),
		m_Mixer(Mixer::Get()) 
	{
		TTF_Init();
		if (m_SDLInit != 0) {
			throw SDL_GetError();
		}
	};

	SDL& SDL::Get() { 
		static SDL instance;
		return instance; 
	}

	const Mixer& SDL::GetMixer() const {
		return m_Mixer;
	}

	int SDL::PollEvents() {
		return SDL_PollEvent(&(this->m_SDLEvent));
	}

	const SDL_Event& SDL::GetEvent() {
		return this->m_SDLEvent;
	}

	bool SDL::CheckKey(SDL_Scancode key) {
		return this->m_KeyStates[key];
	}

	bool SDL::CheckKey(const char* key) {
		return this->m_KeyStates[SDL_GetScancodeFromName(key)];
	}
}


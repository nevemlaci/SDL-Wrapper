#include "cpp_SDL_Mix_Music.hpp"

namespace SDL {
	MixMusic::MixMusic(const char* path) : m_SDLMusic(Mix_LoadMUS(path)) {
		if (!m_SDLMusic) {
			throw SDL_GetError();
		}
	}

	MixMusic::~MixMusic() {
		Mix_FreeMusic(this->m_SDLMusic);
	}

	Mix_Music* MixMusic::GetSDLMusic() const { return this->m_SDLMusic; }
}
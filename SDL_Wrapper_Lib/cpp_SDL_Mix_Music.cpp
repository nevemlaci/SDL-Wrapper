#include "cpp_SDL_Mix_Music.hpp"

namespace SDL {
	MixMusic::MixMusic(const char* path) 
		: m_SDLMusic(Mix_LoadMUS(path)), m_MusicVolume(15) {
		if (!m_SDLMusic) {
			throw SDL_GetError();
		}
	}

	MixMusic::~MixMusic() {
		Mix_FreeMusic(this->m_SDLMusic);
	}
	
	void MixMusic::Play(int loops) const {
		Mix_PlayMusic(this->m_SDLMusic, loops);
	}

	unsigned int MixMusic::SetMusicVolume(unsigned int volume) const {
		m_MusicVolume = volume > 128 ? 128 : volume;
		Mix_VolumeMusic(volume);
		return m_MusicVolume;
	}

	unsigned int MixMusic::GetMusicVolume() const {
		return m_MusicVolume;
	}

	Mix_Music* MixMusic::GetSDLMusic() const { return this->m_SDLMusic; }
}
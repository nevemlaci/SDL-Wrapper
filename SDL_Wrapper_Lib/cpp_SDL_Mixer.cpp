#include "cpp_SDL_Mixer.hpp"
#include "SDL.h"

namespace SDL {
	Mixer::Mixer()
		:
		m_MusicVolume(10)
	{
		SDL_Init(SDL_INIT_AUDIO);
		Mix_Init(MIX_INIT_MP3 | MIX_INIT_OGG);
	}

	const Mixer& Mixer::Get() {
		static Mixer m;
		return m;
	}

	
	void Mixer::OpenAudio(int frequency, Uint16 format, int channels, int chunk_size) const {
		if (Mix_OpenAudio(frequency, format, channels, chunk_size) == -1) {
			throw SDL_GetError();
		}
	}

	unsigned int Mixer::SetMusicVolume(unsigned int volume) const {
		m_MusicVolume = volume>128 ? 128 : volume;
		Mix_VolumeMusic(volume);
		return m_MusicVolume;
	}

	unsigned int Mixer::GetMusicVolume() const {
		return m_MusicVolume;
	}
}
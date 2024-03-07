#include "cpp_SDL_Mixer.hpp"
#include "SDL.h"

namespace SDL {
	Mixer::Mixer()
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
}
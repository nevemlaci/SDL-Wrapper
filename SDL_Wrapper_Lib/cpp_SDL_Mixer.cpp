#include "cpp_SDL_Mixer.hpp"
#include "SDL.h"

namespace SDL {
	void Mixer::OpenAudio(int frequency, Uint16 format, int channels, int chunk_size) {
		if (Mix_OpenAudio(frequency, format, channels, chunk_size) == -1) {
			throw SDL_GetError();
		}
	}	
}
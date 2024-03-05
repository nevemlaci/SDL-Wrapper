#include "cpp_SDL_Mixer.hpp"

namespace SDL {
	Mixer::Mixer() {
		if (Mix_OpenAudio(48000, MIX_DEFAULT_FORMAT, 1, 1024) == -1) {
			throw SDL_GetError();
		}
	}

	const Mixer& Mixer::Get() {
		static Mixer m;
		return m;
	}

	void Mixer::PlayMusic(const MixMusic& music) {
		Mix_PlayMusic(music.GetSDLMusic(), 0);
	}

	void Mixer::PlayMusic(const MixMusic& music, int loopAmount) {
		Mix_PlayMusic(music.GetSDLMusic(), loopAmount);
	}
}
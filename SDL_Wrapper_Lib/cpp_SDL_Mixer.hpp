#ifndef __CPPSDL_MIXER__
#define __CPPSDL_MIXER__
#include <SDL_mixer.h>
#include "cpp_SDL_Mix_Music.hpp"
namespace SDL {
	/// @brief Singleton class for wrapping SDL Mixer
	class Mixer {

	public:

		Mixer(const Mixer&) = delete;
		Mixer operator=(const Mixer&) = delete;

		/// @brief get static instance reference to Mixer
		/// @return static instance reference to Mixer
		static const Mixer& Get();
		/// @brief start a music and play it once
		/// @param music music to be player
		void PlayMusic(const MixMusic& music);
		
		/// @brief start a music and loop it
		/// @param music music to be player
		/// @param loopAmount amount of times to be looped (0 means play it once)
		void PlayMusic(const MixMusic& music, int loopAmount);
	private:
		Mixer();

	};
}
#endif

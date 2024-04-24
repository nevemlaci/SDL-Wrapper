#ifndef __CPPSDL_MIXER__
#define __CPPSDL_MIXER__
#include <SDL_mixer.h>


namespace SDL {
	namespace Mixer {

		/// @brief Open the default audio device for playback. An audio device is what generates sound,
		/// so the app must open one to play audio.
		/// @param frequency frequency the frequency to playback audio at (in Hz).
		/// @param format format audio format, one of SDL's AUDIO_* values. (Use MIX_DEFAULT_FORMAT for default)
		/// @param channels channels number of channels (1 is mono, 2 is stereo, etc).
		/// @param chunk_size audio buffer size in sample FRAMES (total samples divided by channel count).
		void OpenAudio(int frequency, Uint16 format, int channels, int chunk_size);
	}
	

}
#endif

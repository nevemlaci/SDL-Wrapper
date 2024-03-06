#ifndef __CPPSDL_MIXER__
#define __CPPSDL_MIXER__
#include <SDL_mixer.h>

namespace SDL {
	/// @brief Singleton class for wrapping SDL Mixer
	class Mixer {

	friend class SDL;

	public:

		Mixer(const Mixer&) = delete;
		Mixer operator=(const Mixer&) = delete;


		/// @brief Open the default audio device for playback. An audio device is what generates sound,
		/// so the app must open one to play audio.
		/// @param frequency frequency the frequency to playback audio at (in Hz).
		/// @param format format audio format, one of SDL's AUDIO_* values. (Use MIX_DEFAULT_FORMAT for default)
		/// @param channels channels number of channels (1 is mono, 2 is stereo, etc).
		/// @param chunk_size audio buffer size in sample FRAMES (total samples divided by channel count).
		void OpenAudio(int frequency, Uint16 format, int channels, int chunk_size) const;

		/// @brief Sets the volume for all channels
		/// @param volume volume value(0-128)
		/// @return returns the new volume
		int SetMusicVolume(unsigned int volume) const;

		/// @brief 
		/// @return returns the current volume
		int GetMusicVolume() const;
	private:
		Mixer();

		/// @brief get static instance reference to Mixer. Used internally, get the Mixer instance from the SDL singleton.
		/// @return static instance reference to Mixer
		static const Mixer& Get();

		mutable int m_Volume;
	};
}
#endif

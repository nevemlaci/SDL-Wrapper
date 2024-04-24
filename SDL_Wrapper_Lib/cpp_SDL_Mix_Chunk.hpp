#ifndef __CPPSDL_MIXER_CHUNK__
#define __CPPSDL_MIXER_CHUNK__

#include <SDL_mixer.h>

namespace SDL {
	class MixChunk final
	{
	public:
		/// @brief Constructor. Loads a chunk
		/// @param path path to the audio file to be loaded
		MixChunk(const char* path);

		~MixChunk();

		/// @brief Play the chunk
		/// @param channel the channel to play the chunk on. -1 for the first available channel
		/// @param loops how many times should the chunk be looped. 0 for playing it only once.
		void Play(int channel = -1, int loops = 0);

		Mix_Chunk* GetSDLChunk() const;

		/// @brief Sets the volume of the chunk
		/// @param volume volume to be set, 0-128
		/// @return returns the new volume
		unsigned int SetVolume(unsigned int volume);

		int GetVolume() const;

	private:
		int m_Volume;
		Mix_Chunk* m_SDLChunk;

	};

}

#endif

#ifndef __CPPSDL_MIXER_MUSIC__
#define __CPPSDL_MIXER_MUSIC__
#include <SDL_mixer.h>


namespace SDL {

class MixMusic final{
public:

	MixMusic(const char* path);

	~MixMusic();

	/// @brief Play the music on the music channel
	/// @param loops how many times should the music be looped. 0 for playing it only once.
	void Play(int loops = 0) const;

	/// @brief Sets the volume for all channels
	/// @param volume volume value(0-128)
	/// @return returns the new volume
	unsigned int SetMusicVolume(unsigned int volume);

	/// @brief 
	/// @return returns the current volume
	unsigned int GetMusicVolume() const;

	/// @brief 
	/// @return the stored Mix_Music* 
	Mix_Music* GetSDLMusic() const;
private:
	unsigned int m_MusicVolume;

	Mix_Music* m_SDLMusic;
};

}
#endif

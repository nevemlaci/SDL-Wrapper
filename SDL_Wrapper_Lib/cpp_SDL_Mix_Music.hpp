#ifndef __CPPSDL_MIXER_MUSIC__
#define __CPPSDL_MIXER_MUSIC__
#include <SDL_mixer.h>


namespace SDL {

class MixMusic{
public:

	MixMusic(const char* path);

	~MixMusic();

	/// @brief Play the music on the music channel
	/// @param loops how many times should the music be looped. 0 for playing it only once.
	void Play(int loops = 0) const;

	/// @brief 
	/// @return the stored Mix_Music* 
	Mix_Music* GetSDLMusic() const;
private:
	Mix_Music* m_SDLMusic;
};

}
#endif

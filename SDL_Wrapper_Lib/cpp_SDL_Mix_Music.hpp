#ifndef __CPPSDL_MIXER_MUSIC__
#define __CPPSDL_MIXER_MUSIC__
#include <SDL_mixer.h>

namespace SDL {

class MixMusic{
public:
	MixMusic(const char* path);
	~MixMusic();

	Mix_Music* GetSDLMusic() const;
private:
	Mix_Music* m_SDLMusic;
};

}
#endif

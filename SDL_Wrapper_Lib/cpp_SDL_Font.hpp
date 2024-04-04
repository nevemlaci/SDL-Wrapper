#ifndef __CPPSDLFONT__
#define __CPPSDLFONT__
#include <SDL_ttf.h>

namespace SDL {
	class Font{
	public:
		Font(const char* path, unsigned int font_size = 14);
		~Font();

		TTF_Font* GetTTFFont() const;
	private:
		TTF_Font* m_SDLFont;
	};
}

#endif

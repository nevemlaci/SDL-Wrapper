#ifndef __CPPSDLTEXTURE__
#define __CPPSDLTEXTURE__

#include "cpp_SDL.hpp"
#include "cpp_SDL_Window.hpp"
#include "cpp_SDL_Rect.hpp"
#include "SDL_image.h"

namespace SDL {
	class Renderer;

	class Texture {
	public:
		Texture(const char* path, Renderer& renderer);

		~Texture();

		SDL_Texture* GetSDLTexture() const;
	private:
		SDL_Texture* sdltexture;
	};
}

#endif

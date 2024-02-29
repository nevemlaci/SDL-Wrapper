#ifndef __CPPSDLRENDERER__
#define __CPPSDLRENDERER__
#include "cpp_SDL_Window.hpp"
#include "cpp_SDL_Rect.hpp"
#include "cpp_SDL_Texture.hpp"

namespace SDL {
	class Renderer {
	public:
		Renderer(const Window& p_window, int index, Uint32 flags);
		
		SDL_Renderer* GetSDLRenderer();

		void RenderCopy(const Texture& texture, double angle);

		void RenderCopySrc(const Texture& texture, Rect srcrect, double angle);

		void RenderCopyDst(const Texture& texture, Rect dstrect, double angle);

		void RenderCopyEx(const Texture& texture, Rect srcrect, Rect dstrect, double angle);

		void RenderClear();

		void RenderPresent();
	private:
		const Window& window;
		SDL_Renderer* sdlrenderer;
	};
}

#endif

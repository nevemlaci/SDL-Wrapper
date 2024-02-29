#ifndef __CPPSDLRENDERER__
#define __CPPSDLRENDERER__
#include "cpp_SDL_Window.hpp"

namespace SDL {
	class Renderer {
	public:
		Renderer(const Window& p_window, int index, Uint32 flags);
	private:
		const Window& window;
		SDL_Renderer* sdlrenderer;
	};
}

#endif

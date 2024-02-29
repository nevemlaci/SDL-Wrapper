#include "cpp_SDL_Renderer.hpp"

namespace SDL {
	Renderer::Renderer(const Window& p_window, int index, Uint32 flags) 
		: window(p_window), sdlrenderer(SDL_CreateRenderer(p_window.GetWindow(), index, flags)) {

	}
}
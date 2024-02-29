#include "cpp_SDL_Renderer.hpp"

namespace SDL {
	Renderer::Renderer(const Window& p_window, int index, Uint32 flags)
		: window(p_window), sdlrenderer(SDL_CreateRenderer(p_window.GetWindow(), index, flags)) {

	}

	SDL_Renderer* Renderer::GetSDLRenderer() {
		return this->sdlrenderer;
	}

	void Renderer::RenderCopy(const Texture& texture, double angle) {
		SDL_RenderCopyExF(this->sdlrenderer, texture.GetSDLTexture(), NULL, NULL, angle, NULL, SDL_FLIP_NONE);
	}

	void Renderer::RenderCopySrc(const Texture& texture, Rect srcrect, double angle) {
		SDL_Rect srcr = srcrect.GetSDLRect();
		SDL_RenderCopyExF(this->sdlrenderer, texture.GetSDLTexture(), &srcr, NULL, angle, NULL, SDL_FLIP_NONE);
	}

	void Renderer::RenderCopyDst(const Texture& texture, Rect dstrect, double angle) {
		SDL_FRect dstr = dstrect.GetSDLFRect();
		SDL_RenderCopyExF(this->sdlrenderer, texture.GetSDLTexture(), NULL, &dstr, angle, NULL, SDL_FLIP_NONE);
	}

	void Renderer::RenderCopyEx(const Texture& texture, Rect srcrect, Rect dstrect, double angle) {
		SDL_Rect srcr = srcrect.GetSDLRect();
		SDL_FRect dstr = dstrect.GetSDLFRect();
		SDL_RenderCopyExF(this->sdlrenderer, texture.GetSDLTexture(), &srcr, &dstr, angle, NULL, SDL_FLIP_NONE);
	}

	void Renderer::RenderClear() {
		SDL_RenderClear(this->sdlrenderer);
	}

	void Renderer::RenderPresent() {
		SDL_RenderPresent(this->sdlrenderer);
	}
}
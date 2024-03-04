#include "cpp_SDL_Renderer.hpp"

//

namespace SDL {
	Renderer::Renderer(const Window& p_window, int index, Uint32 flags)
		: window(p_window), sdlrenderer(SDL_CreateRenderer(p_window.GetWindow(), index, flags)), insertmode(src), nextrect({0, 0, 0, 0}) {
		if (!sdlrenderer) {
			throw SDL_GetError();
		}
	}

	Renderer::~Renderer() {
		SDL_DestroyRenderer(this->sdlrenderer);
	}

	SDL_Renderer* Renderer::GetSDLRenderer() const {
		return this->sdlrenderer;
	}
	
	void Renderer::RenderCopy(const Texture& texture, double angle) const {
		SDL_RenderCopyExF(this->sdlrenderer, texture.GetSDLTexture(), NULL, NULL, angle, NULL, SDL_FLIP_NONE);
	}

	void Renderer::RenderCopySrc(const Texture& texture, Rect srcrect, double angle) const {
		SDL_Rect srcr = srcrect.GetSDLRect();
		SDL_RenderCopyExF(this->sdlrenderer, texture.GetSDLTexture(), &srcr, NULL, angle, NULL, SDL_FLIP_NONE);
	}

	void Renderer::RenderCopyDst(const Texture& texture, Rect dstrect, double angle) const {
		SDL_FRect dstr = dstrect.GetSDLFRect();
		SDL_RenderCopyExF(this->sdlrenderer, texture.GetSDLTexture(), NULL, &dstr, angle, NULL, SDL_FLIP_NONE);
	}

	void Renderer::RenderCopyEx(const Texture& texture, Rect srcrect, Rect dstrect, double angle) const {
		SDL_Rect srcr = srcrect.GetSDLRect();
		SDL_FRect dstr = dstrect.GetSDLFRect();
		SDL_RenderCopyExF(this->sdlrenderer, texture.GetSDLTexture(), &srcr, &dstr, angle, NULL, SDL_FLIP_NONE);
	}

	void Renderer::RenderClear() const {
		SDL_RenderClear(this->sdlrenderer);
	}

	void Renderer::RenderPresent() const {
		SDL_RenderPresent(this->sdlrenderer);
	}

	void Renderer::EnableVsync() const {
		SDL_RenderSetVSync(this->sdlrenderer, 1);
	}

	void Renderer::DisableVsync() const {
		SDL_RenderSetVSync(this->sdlrenderer, 0);
	}

	void Renderer::SetRenderColor(int r, int g, int b, int a) const {
		SDL_SetRenderDrawColor(this->sdlrenderer, r, g, b, a);
	}


	Renderer& Renderer::operator<<(const at& a) {
		this->insertmode = dst;
		this->nextrect = a.getrect();
		return (*this);
	}

	Renderer& Renderer::operator<<(const from& f) {
		this->insertmode = src;
		this->nextrect = f.getrect();
		return (*this);
	}

	Renderer& Renderer::operator<<(const Texture& texture) {
		this->insertmode == dst ? this->RenderCopyDst(texture, this->nextrect) : this->RenderCopySrc(texture, this->nextrect);
		
		return (*this);
	}

}
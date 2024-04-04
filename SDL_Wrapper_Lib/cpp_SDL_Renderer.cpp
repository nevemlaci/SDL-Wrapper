#include "cpp_SDL_Renderer.hpp"

namespace SDL {
	Renderer::Renderer(const Window& p_window, int index, Uint32 flags)
		: m_Window(p_window), m_SDLRenderer(SDL_CreateRenderer(p_window.GetWindow(), index, flags)), m_InsertMode(src), m_NextRect({0, 0, 0, 0}) {
		if (!m_SDLRenderer) {
			throw SDL_GetError();
		}
	}

	Renderer::~Renderer() {
		SDL_DestroyRenderer(this->m_SDLRenderer);
	}

	SDL_Renderer* Renderer::GetSDLRenderer() const {
		return this->m_SDLRenderer;
	}
	
	void Renderer::RenderCopy(const Texture& texture, double angle) const {
		SDL_RenderCopyExF(this->m_SDLRenderer, texture.GetSDLTexture(), NULL, NULL, angle, NULL, SDL_FLIP_NONE);
	}

	void Renderer::RenderCopySrc(const Texture& texture, Rect srcrect, double angle) const {
		SDL_Rect srcr = srcrect.GetSDLRect();
		SDL_RenderCopyExF(this->m_SDLRenderer, texture.GetSDLTexture(), &srcr, NULL, angle, NULL, SDL_FLIP_NONE);
	}

	void Renderer::RenderCopyDst(const Texture& texture, Rect dstrect, double angle) const {
		SDL_FRect dstr = dstrect.GetSDLFRect();
		SDL_RenderCopyExF(this->m_SDLRenderer, texture.GetSDLTexture(), NULL, &dstr, angle, NULL, SDL_FLIP_NONE);
	}

	void Renderer::RenderCopyEx(const Texture& texture, Rect srcrect, Rect dstrect, double angle) const {
		SDL_Rect srcr = srcrect.GetSDLRect();
		SDL_FRect dstr = dstrect.GetSDLFRect();
		SDL_RenderCopyExF(this->m_SDLRenderer, texture.GetSDLTexture(), &srcr, &dstr, angle, NULL, SDL_FLIP_NONE);
	}

	void Renderer::RenderClear() const {
		SDL_RenderClear(this->m_SDLRenderer);
	}

	void Renderer::RenderPresent() const {
		SDL_RenderPresent(this->m_SDLRenderer);
	}

	void Renderer::EnableVsync() const {
		SDL_RenderSetVSync(this->m_SDLRenderer, 1);
	}

	void Renderer::DisableVsync() const {
		SDL_RenderSetVSync(this->m_SDLRenderer, 0);
	}

	void Renderer::SetRenderColor(int r, int g, int b, int a) const {
		SDL_SetRenderDrawColor(this->m_SDLRenderer, r, g, b, a);
	}


	Renderer& Renderer::operator<<(const at& at) {
		this->m_InsertMode = dst;
		this->m_NextRect = at.getrect();
		return (*this);
	}

	Renderer& Renderer::operator<<(const from& from) {
		this->m_InsertMode = src;
		this->m_NextRect = from.getrect();
		return (*this);
	}

	Renderer& Renderer::operator<<(const Texture& texture) {
		this->m_InsertMode == dst ? this->RenderCopyDst(texture, this->m_NextRect) : this->RenderCopySrc(texture, this->m_NextRect);
		
		return (*this);
	}

}
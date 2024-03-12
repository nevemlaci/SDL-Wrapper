#include "cpp_SDL_Texture.hpp"
#include "cpp_SDL_Renderer.hpp"

namespace SDL {
	Texture::Texture(): m_SDLTexture(nullptr) {
		
	}

	Texture::Texture(const char* path, Renderer& renderer) : m_SDLTexture(IMG_LoadTexture(renderer.GetSDLRenderer(), path)) {
		if (!m_SDLTexture) {
			throw SDL_GetError();
		}
	}

	Texture::Texture(SDL_Texture* texture)
		:
		m_SDLTexture(texture)
	{
		if (!m_SDLTexture) {
			throw SDL_GetError();
		}
	}

	Texture::~Texture() {
		SDL_DestroyTexture(this->m_SDLTexture);
	}

	SDL_Texture* Texture::GetSDLTexture() const {
		return this->m_SDLTexture;
	}
}
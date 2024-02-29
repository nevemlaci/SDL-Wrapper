#include "cpp_SDL_Texture.hpp"
#include "cpp_SDL_Renderer.hpp"

namespace SDL {
	Texture::Texture(const char* path, Renderer& renderer) : sdltexture(IMG_LoadTexture(renderer.GetSDLRenderer(), path)) {}

	Texture::~Texture() {
		SDL_DestroyTexture(this->sdltexture);
	}

	SDL_Texture* Texture::GetSDLTexture() const {
		return this->sdltexture;
	}
}
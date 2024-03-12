#include "cpp_SDL_Font.hpp"

namespace SDL {
	Font::Font(const char* path, unsigned int font_size) : m_SDLFont(TTF_OpenFont(path, font_size)) {
		if (!m_SDLFont) throw SDL_GetError();
	}

	Font::~Font() {
		TTF_CloseFont(this->m_SDLFont);
	}

	TTF_Font* Font::GetTTFFont() const {
		return this->m_SDLFont;
	}
}
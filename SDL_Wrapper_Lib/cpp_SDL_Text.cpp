#include "cpp_SDL_Text.hpp"
#include "cpp_SDL_Renderer.hpp"

namespace SDL {
	Text::Text(const char* text, const Font& font, const Renderer& renderer, SDL_Color color)
		:m_Text(text)
	{	
		SDL_ClearError();
		m_SDLSurface = TTF_RenderUTF8_Blended_Wrapped(font.GetTTFFont(), text, color, 0);
		if (!m_SDLSurface) throw SDL_GetError();
		m_SDLTexture = SDL_CreateTextureFromSurface(renderer.GetSDLRenderer(), m_SDLSurface);
		if(!m_SDLTexture) throw SDL_GetError();
	}
	Text::~Text() {
		SDL_DestroyTexture(this->GetSDLTexture());
		SDL_FreeSurface(m_SDLSurface);
	}
}
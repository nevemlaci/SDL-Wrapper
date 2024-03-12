#ifndef __CPPSDLTEXT__
#define __CPPSDLTEXT__

#include "cpp_SDL_Texture.hpp"
#include "SDL_ttf.h"
#include "SDL_render.h"
#include "cpp_SDL_Font.hpp"

//Extends original SDL functionality by adding renderable text

namespace SDL {

    class Text : public Texture {
    public: 
        Text(const char* text, const Font& font, const Renderer& renderer);
        
        ~Text();
    private:
        SDL_Surface* m_SDLSurface;
        
        const char* m_Text;
    };

}

#endif

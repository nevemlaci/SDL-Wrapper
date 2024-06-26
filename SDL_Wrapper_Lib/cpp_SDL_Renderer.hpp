#ifndef __CPPSDLRENDERER__
#define __CPPSDLRENDERER__
#include "cpp_SDL_Rect.hpp"
#include "cpp_SDL_Renderermanip.hpp"
#include "cpp_SDL_Texture.hpp"
#include "cpp_SDL_Window.hpp"

namespace SDL {

	enum InsertMode {
		src, dst
	};

	/// @brief Renderer class wrapping SDL_Renderer
	class Renderer final {
	public:
		/// @brief renderer constructor
		/// @param p_window window that the renderer is bound to
		/// @param index index of renderer in the given window
		/// @param flags an SDL renderer flag or multiple flags or'd together
		Renderer(const Window& p_window, int index, Uint32 flags);
		
		/// @brief destructs the renderer(calls the appropriate SDL function for it)
		~Renderer();

		/// @brief getter for the SDL_Renderer
		/// @return returns the SDL_Renderer instance 
		SDL_Renderer* GetSDLRenderer() const;

		/// @brief copies the texture to the renderer
		/// Use this function to copy a whole texture to the whole renderer.
		/// @param texture the texture to be copied
		/// @param angle optional rotation
		void RenderCopy(const Texture& texture, double angle = 0) const;

		/// @brief copies a part of the texture to the renderer
		/// Use this function to copy a part of a texture to the whole renderer.
		/// @param texture the texture to be copied
		/// @param srcrect the rectangle specifying the position and size of the texture part to be copied
		/// @param angle optional rotation
		void RenderCopySrc(const Texture& texture, Rect srcrect, double angle = 0) const;

		/// @brief copies a texture to a specific position on the renderer.
		/// Use this function to copy the whole texture to a given position with a given size.
		/// @param texture the texture to be copied
		/// @param dstrect the rectangle specifying the position and size
		/// @param angle optional rotation
		void RenderCopyDst(const Texture& texture, Rect dstrect, double angle = 0) const;

		/// @brief copies a part of a texture to a specific position on the renderer.
		/// @param texture the texture to be copied
		/// @param srcrect the rectangle specifying the position and size of the texture part to be copied
		/// @param dstrect the rectangle specifying the position and size
		/// @param angle optional rotation
		void RenderCopyEx(const Texture& texture, Rect srcrect, Rect dstrect, double angle = 0) const;

		void SetRenderDrawColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

		void FillRect(const Rect& rect);

		/// @brief Clears the renderer
		void RenderClear() const;

		/// @brief Renders all textures copied to the renderer
		void RenderPresent() const;

		/// @brief Enables VSync
		void EnableVsync() const;

		/// @brief Disables VSync
		void DisableVsync() const;

		/// @brief same as Renderer::RenderCopy
		/// @param texture texture to be copied
		Renderer& operator<<(const Texture& texture);

		/// @brief copies a texture to the rendering target at a rectangle, takes an SDL::at object
		/// @param at the at object specifying the destination rectangle on the rendering target
		Renderer& operator<<(const at& at);

		/// @brief copies a texture to the rendering target from a rectangle, takes an SDL::from object
		/// @param from the SDL::from object specifying the source rectangle on the texture
		Renderer& operator<<(const from& from);


	private:


		///@brief window that the renderer is bound to(rendering context)
		const Window& m_Window;

		/// @brief SDL_Renderer instance
		SDL_Renderer* m_SDLRenderer;

		/// @brief the dstrect of the next texture copied by the inserter operator
		Rect m_NextRect;

		InsertMode m_InsertMode;
	};

	

}


#endif

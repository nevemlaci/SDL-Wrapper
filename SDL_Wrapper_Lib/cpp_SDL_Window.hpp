#ifndef __CPPSDLWINDOW__
#define __CPPSDLWINDOW__
#include <SDL.h>

namespace SDL {
	class Window final {
	public:
		/// @brief Constructs a window. Throws const char* SDL_GetError() if the window initialization failed.
		/// @param title Title of the window
		/// @param x 
		/// @param y 
		/// @param w 
		/// @param h 
		/// @param flags SDL Flag / multiple flags or'd together.
		Window(const char* title, int x, int y, int w, int h, Uint32 flags);
		
		~Window();

		/// @brief 
		/// @return the SDL_Window* of the current Window instance 
		SDL_Window* GetSDLWindow() const;

		/// @brief hides the window
		void HideWindow();

		/// @brief shows the window
		void ShowWindow();


	private:
		SDL_Window* m_SDLWindow;
		
	};
}

#endif
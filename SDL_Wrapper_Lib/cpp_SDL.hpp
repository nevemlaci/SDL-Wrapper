#ifndef __CPPSDL__
#define __CPPSDL__
#include <SDL.h>
#include "cpp_SDL_Mixer.hpp"

namespace SDL {
	/// @brief Singleton SDL class used for initializing SDL.
	/// Take a reference with the getter, this class cannot be constructed(and copied).
	/// It also contains the Event so you don't need to create an SDL_Event like you need with C style SDL
	class SDL {
	public:

		//delete the copy constructor so the class can only be referenced
		SDL(const SDL&) = delete;

		//delete the assignment operator
		SDL operator=(const SDL&) = delete;

		/// @brief Get instance reference of SDL
		/// @return returns the SDL instance reference
		static SDL& Get();

		/// @brief Get the Mixer instance reference
		/// @return the Mixer instance reference
		const Mixer& GetMixer() const;

		/// @brief polls all SDL events, should be used in a while loop inside the main loop to handle all events
		/// @return returns 1 if there was any events, and 0 if there wasn't any
		int PollEvents();
		
		/// @brief getter for the SDL_Event
		/// @return returns the SDL_Event 
		const SDL_Event& GetEvent();

		bool CheckKey(SDL_Scancode key);

		bool CheckKey(const char* key);

	private:
		
		/// @brief initializes SDL. Throws const char* SDL_GetError() if the initialization failed.
		SDL();

		/// @brief return value of SDL_Init
		const int m_SDLInit;

		SDL_Event m_SDLEvent;

		const Mixer& m_Mixer;

		const Uint8* m_KeyStates = SDL_GetKeyboardState(nullptr);
	};
}


#endif
#ifndef __CPPSDL__
#define __CPPSDL__
#include <SDL.h>

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

		/// @brief Get static instance of SDL
		/// @return returns the static SDL instance
		static SDL& Get() ;

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
		const int sdlinit;

		SDL_Event event;

		const Uint8* keyStates = SDL_GetKeyboardState(nullptr);
	};
}


#endif
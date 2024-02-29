#ifndef __CPPSDL__
#define __CPPSDL__
#include <SDL.h>

namespace SDL {
	class SDL {
	public:
		//delete the copy constructor so the class can only be referenced
		SDL(const SDL&) = delete;

		SDL operator=(const SDL&) = delete;

		//get singleton instance
		static SDL& Get() ;

		int PollEvents();

		SDL_Event GetEvent() const ;

	private:
		/// @brief constructor, initializes SDL.
		SDL();

		int sdlinit;

		SDL_Event event;

	};
}


#endif
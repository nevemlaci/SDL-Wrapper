#include <cpp_SDL_include.hpp>
#undef main

int main() {
	SDL::SDL& sdl = SDL::SDL::Get();
	SDL::Window window("asd", 400, 400, 500, 500, 0);
	bool isRunning = true;
	const SDL_Event& event = sdl.GetEvent();
	SDL::MixMusic music("music.wav");
	while (isRunning) {
		sdl.PollEvents();
		switch (event.type) {
		case SDL_QUIT:
			isRunning = false;
			break;
		default: 
			break;
		}
		
	}
	return 0;
}
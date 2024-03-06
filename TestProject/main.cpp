#include <cpp_SDL_include.hpp>
#include <iostream>
#undef main

int main() {
	try {
		SDL::SDL& sdl = SDL::SDL::Get();
		SDL::Window window("asd", 400, 400, 500, 500, 0);
		bool isRunning = true;
		const SDL_Event& event = sdl.GetEvent();
		sdl.GetMixer().OpenAudio(48000, MIX_DEFAULT_FORMAT, 1, 1024);
		SDL::MixMusic m("music.wav");
		sdl.GetMixer().SetMusicVolume(10);
		sdl.GetMixer().PlayMusic(m);
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
	}
	catch (const char* excep) {
		std::cout << excep;
		return -1;
	}
	return 0;
}
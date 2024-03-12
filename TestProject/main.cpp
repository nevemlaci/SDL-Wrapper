#include <cpp_SDL_include.hpp>
#include <iostream>
#undef main

int main() {
	try {
		//Get SDL instance reference
		SDL::SDL& sdl = SDL::SDL::Get();

		//Construct a window
		SDL::Window window("SDL_Wrapper Test Window", 400, 400, 500, 500, SDL_WINDOW_RESIZABLE);

		//Create a renderer, set our window as the rendering context
		SDL::Renderer renderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

		//Construct a texture by providing a path to our source file and specifying what renderer should decode it.
		SDL::Texture tx("texture.png", renderer);

		//Get the mixer index and open an audio channel with it
		sdl.GetMixer().OpenAudio(48000, MIX_DEFAULT_FORMAT, 1, 1024);

		//Construct an audio chunk by loading an audio file
		SDL::MixChunk sfx("Explosion.wav");

		//Set the volume of the chunk
		sfx.SetVolume(12);

		//Play the chunk once
		sfx.Play();

		//Construct a new MixMusic
		SDL::MixMusic ms("music.mp3");

		//Set the music volume to 7 
		ms.SetMusicVolume(10);

		//Play the music
		ms.Play();

		//Load text "asd" with comic.ttf font with the default renderer
		SDL::Text t("asd", SDL::Font ("comic.ttf", 40), renderer);

		//Set the render color for RenderClear
		renderer.SetRenderColor(160, 233, 250, 255);

		//This variable indicates if the main loop should be running or not
		bool isRunning = true;

		//Get a const reference to the event queue of SDL
		const SDL_Event& event = sdl.GetEvent();

		while (isRunning) {
			//Until we have events we ask for the next one
			while (sdl.PollEvents()) {
				//Decide what to do based on the event type
				switch (event.type) {
				//If all windows get closed the program shouldn't be running anymore
				case SDL_QUIT:
					isRunning = false;
					break;
				//If there is a keypress we print a message to cout
				case SDL_KEYDOWN:
					std::cout << "KeyDown\n";
					break;
				//In every other case we do nothing.
				default:
					break;
				}
			}
			//We clear the renderer
			renderer.RenderClear();

			//Copy tx texture onto the rendering target 
			//at position (10, 10) with dimensions (50, 50)	
			renderer << SDL::at({ 10, 10, 50, 50 }) << tx;

			//Copy t text onto the rendering target 
			//at position (10, 30) with dimensions (100, 100)	
			renderer << SDL::at({ 10, 60, 50, 50 }) << t;
				
			//We render everything that is currently copied onto the rendering target
			renderer.RenderPresent();
		}
	}
	catch (const char* excep) {
		std::cout << excep;
		return -1;
	}
	return 0;
}

//-----------------------------------
/*
	The music used in this example: (instrumental version)
	Song: BIMINI - No Way (with Avi Snow) [NCS Release]
	Music provided by NoCopyrightSounds
	Free Download/Stream: http://ncs.io/noway
	Watch: AT/youtube
*/
//-----------------------------------
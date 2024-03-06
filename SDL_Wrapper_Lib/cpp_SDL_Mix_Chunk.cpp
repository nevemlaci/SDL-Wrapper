#include "cpp_SDL_Mix_Chunk.hpp"

namespace SDL {
	MixChunk::MixChunk(const char* path) 
		: m_SDLChunk(Mix_LoadWAV(path))
	{}

	MixChunk::~MixChunk() {
		Mix_FreeChunk(this->m_SDLChunk);
	}

	void MixChunk::Play(int channel, int loops) {
		Mix_PlayChannel(-1, m_SDLChunk, 0);
	}

	Mix_Chunk* MixChunk::GetSDLChunk() const {
		return m_SDLChunk;
	}
}
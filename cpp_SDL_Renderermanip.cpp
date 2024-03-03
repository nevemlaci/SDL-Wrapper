#include "cpp_SDL_Renderermanip.hpp"

namespace SDL {
	at::at(const Rect& rect) : rect(rect) {}
	const Rect& at::getrect() const { return rect; }


	from::from(const Rect& rect) : rect(rect) {};
	const Rect& from::getrect() const { return rect; }
}
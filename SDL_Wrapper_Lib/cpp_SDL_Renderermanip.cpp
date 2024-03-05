#include "cpp_SDL_Renderermanip.hpp"

namespace SDL {
	at::at(const Rect& rect) : m_Rect(rect) {}
	const Rect& at::getrect() const { return m_Rect; }


	from::from(const Rect& rect) : m_Rect(rect) {};
	const Rect& from::getrect() const { return m_Rect; }
}
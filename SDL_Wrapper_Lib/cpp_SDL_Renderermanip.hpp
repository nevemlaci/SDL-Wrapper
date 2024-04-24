#ifndef __CPPSDLRENDERERMANIP__
#define __CPPSDLRENDERERMANIP__
#include "cpp_SDL_Rect.hpp"

namespace SDL {
	/// @brief helper class for the operator<< overload
	class at final {
	public:
		/// @brief explicit constructor(so SDL::Rect cannot be implicitly converted to SDL::at)
		/// @param rect rectangle to be saved as destination
		explicit at(const Rect& rect);
		const Rect& getrect() const;
	private:
		const Rect& m_Rect;
	};

	class from final {
	public:
		/// @brief explicit constructor(so SDL::Rect cannot be implicitly converted to SDL::from)
		/// @param rect rectangle to be saved as source
		explicit from(const Rect& rect);
		const Rect& getrect() const;
	private:
		const Rect& m_Rect = { 0, 0, 0, 0 };
	};
}

#endif
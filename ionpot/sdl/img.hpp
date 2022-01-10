#pragma once

#include "rwops.hpp"
#include "surface.hpp"
#include "video.hpp"

#include <util/macros.hpp>

#include <memory> // std::shared_ptr
#include <string>

namespace ionpot::sdl {
	class Img {
	public:
		using Flags = int;

		static const Flags default_flags;
		static bool was_init;

		static std::string version_str();

		Img(std::shared_ptr<Video>, Flags = default_flags);
		~Img();
		IONPOT_NO_COPY(Img)

		Surface load_png(const RWops&) const;

	private:
		std::shared_ptr<Video> m_video;
	};
}

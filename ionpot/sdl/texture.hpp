#pragma once

#include "point.hpp"
#include "renderer.hpp"
#include "size.hpp"
#include "surface.hpp"

#include <util/macros.hpp>
#include <util/rgba.hpp>

#include <SDL.h>

#include <memory> // std::shared_ptr

namespace ionpot::sdl {
	class Texture {
	public:
		using Flags = Uint32;

		Texture(std::shared_ptr<const Renderer>, Size, Flags);
		Texture(std::shared_ptr<const Renderer>, const Surface&);
		~Texture();
		IONPOT_NO_COPY(Texture)
		IONPOT_DECLARE_MOVE(Texture)

		Size query_size() const;

		void render(Point dst_pos, Size dst_size) const;
		void render(Point dst_pos, Size dst_size, Point src_pos, Size src_size) const;

		void set_blend() const;

	protected:
		std::shared_ptr<const Renderer> m_renderer;
		SDL_Texture* m_texture;

	private:
		Texture(std::shared_ptr<const Renderer>, SDL_Texture*);
	};

	class TargetTexture : public Texture {
	public:
		TargetTexture(std::shared_ptr<const Renderer>, Size);
		TargetTexture(std::shared_ptr<const Renderer>, Size, const util::RGBA&);
		void set_as_target() const;
	};
}

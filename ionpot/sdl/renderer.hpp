#pragma once

#include "point.hpp"
#include "size.hpp"
#include "window.hpp"

#include <util/hexagon.hpp>
#include <util/macros.hpp>
#include <util/rgba.hpp>

#include <SDL.h>

#include <memory> // std::shared_ptr

namespace ionpot::sdl {
	class Renderer {
		friend class Texture;
		friend class TargetTexture;

	public:
		using Flags = Uint32;

		static const Flags default_flags;

		Renderer(std::shared_ptr<const Window>, Flags = default_flags);
		~Renderer();
		IONPOT_NO_COPY(Renderer)
		IONPOT_DECLARE_MOVE(Renderer)

		void clear() const;
		void draw_hex(const util::Hexagon&) const;
		void draw_line(Point start, Point end) const;
		void draw_rect(Point position, Size size) const;
		void present() const;
		Size query_output_size() const;
		void reset_color() const;
		void reset_target() const;
		void set_blendmode(SDL_BlendMode) const;
		void set_color(const util::RGBA&) const;

	private:
		std::shared_ptr<const Window> m_window;
		SDL_Renderer* m_renderer;
	};
}

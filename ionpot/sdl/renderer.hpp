#pragma once

#include "font.hpp"
#include "hexagon.hpp"
#include "line.hpp"
#include "rect.hpp"
#include "surface.hpp"
#include "texture.hpp"

#include <util/macros.hpp>
#include <util/point.hpp>
#include <util/rgba.hpp>
#include <util/size.hpp>

#include <SDL.h>
#include <memory> // std::shared_ptr
#include <string>

namespace ionpot::sdl {
	class Renderer {
		friend struct Context;
		friend class Window;
	public:
		void clear() const;
		Texture create_hex(const Hexagon&, const util::RGBA&) const;
		Texture create_text(const Font&, std::string text) const;
		Texture create_text(const Font&, std::string text, const util::RGBA&) const;
		Texture create_texture(const Surface& surface) const;
		TargetTexture create_texture(util::Size) const;
		SharedTexture shared_texture(const Surface& surface) const;
		std::shared_ptr<TargetTexture> shared_texture(util::Size) const;
		void draw_hex(const Hexagon&) const;
		void draw_line(Line) const;
		void draw_rect(const Rect&) const;
		void present() const;
		void put(const Texture&, util::Point position) const;
		void put(const SharedTexture&, util::Point position) const;
		void reset_color() const;
		void reset_target() const;
		void set_color(const util::RGBA&) const;
		void set_target(const TargetTexture&) const;
	private:
		SDL_Renderer* m_renderer;
		Renderer(SDL_Window*);
		~Renderer();
		IONPOT_NO_COPY(Renderer)
		IONPOT_DECLARE_MOVE(Renderer)
	};
}

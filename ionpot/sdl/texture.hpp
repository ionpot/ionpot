#pragma once

#include "point.hpp"
#include "renderer.hpp"
#include "size.hpp"
#include "surface.hpp"

#include <util/macros.hpp>

#include <SDL.h>

#include <memory> // std::shared_ptr

namespace ionpot::sdl {
	class Texture {
	public:
		using Flags = Uint32;

		Texture(std::shared_ptr<Renderer>, Size, Flags);
		Texture(std::shared_ptr<Renderer>, const Surface&);
		~Texture();
		IONPOT_NO_COPY(Texture)
		IONPOT_DECLARE_MOVE(Texture)

		Size query_size() const;

		void render(Point dst_pos, Size dst_size) const;
		void render(Point dst_pos, Size dst_size, Point src_pos, Size src_size) const;

		void set_blend() const;

	protected:
		std::shared_ptr<Renderer> m_renderer;
		SDL_Texture* m_texture;

	private:
		Texture(std::shared_ptr<Renderer>, SDL_Texture*);
	};

	class TargetTexture : public Texture {
	public:
		TargetTexture(std::shared_ptr<Renderer>, Size);
		const Renderer& set_as_target() const;
	};

	class SizedTexture {
	public:
		SizedTexture(Texture&&);
		SizedTexture(Texture&&, Size);

		Size size() const;

		void render(Point position) const;

	private:
		Texture m_texture;
		Size m_size;
	};
}

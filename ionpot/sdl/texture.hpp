#pragma once

#include "renderer.hpp"
#include "surface.hpp"

#include <util/macros.hpp>
#include <util/point.hpp>
#include <util/rgba.hpp>
#include <util/size.hpp>

#include <SDL.h>

#include <memory> // std::shared_ptr

namespace ionpot::sdl {
	class Texture {
	public:
		using Alpha = Uint8;
		using Flags = Uint32;

		Texture(std::shared_ptr<const Renderer>, util::Size, Flags);
		Texture(std::shared_ptr<const Renderer>, const Surface&);
		~Texture();
		IONPOT_NO_COPY(Texture)
		IONPOT_DECLARE_MOVE(Texture)

		util::Size query_size() const;

		void render(
			util::Point dst_pos,
			util::Size dst_size) const;

		void render(
			util::Point dst_pos,
			util::Size dst_size,
			util::Point src_pos,
			util::Size src_size) const;

		void set_alpha(Alpha) const;
		void set_blend() const;

	protected:
		std::shared_ptr<const Renderer> m_renderer;
		SDL_Texture* m_texture;

	private:
		Texture(std::shared_ptr<const Renderer>, SDL_Texture*);
	};

	class TargetTexture : public Texture {
	public:
		TargetTexture(std::shared_ptr<const Renderer>, util::Size);
		TargetTexture(std::shared_ptr<const Renderer>, util::Size, const util::RGBA&);
		void set_as_target() const;
	};
}

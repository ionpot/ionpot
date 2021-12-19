#pragma once

#include "surface.hpp"

#include <util/macros.hpp>
#include <util/size.hpp>

#include <SDL.h>

#include <memory> // std::shared_ptr

namespace ionpot::sdl {
	class Texture {
	public:
		util::Size size() const;
		~Texture();
		IONPOT_NO_COPY(Texture)
		IONPOT_DECLARE_MOVE(Texture)
	protected:
		friend class Renderer;
		util::Size m_size;
		SDL_Texture* m_texture;
		Texture(SDL_Texture*, util::Size = {});
		Texture(SDL_Renderer*, util::Size, Uint32 flags);
		Texture(SDL_Renderer*, const Surface&);
	};

	class TargetTexture : public Texture {
		friend class Renderer;
		TargetTexture(SDL_Renderer*, util::Size);
	};

	class SharedTexture {
	public:
		util::Size size() const;
	private:
		friend class Renderer;
		std::shared_ptr<Texture> m_texture;
		SharedTexture(std::shared_ptr<Texture>);
		SharedTexture(std::shared_ptr<TargetTexture>);
		const Texture& get() const;
	};
}

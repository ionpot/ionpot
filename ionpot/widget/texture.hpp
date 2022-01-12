#pragma once

#include "box.hpp"
#include "point.hpp"
#include "size.hpp"

#include <sdl/font.hpp>
#include <sdl/texture.hpp>

namespace ionpot::widget {
	class Texture : public Box {
	public:
		Texture(sdl::Texture&&);
		Texture(sdl::Texture&&, const sdl::Font&);
		Texture(sdl::Texture&&, Size);

		void position(Point) override;
		Point position() const override;

		void render() const;

		Size size() const override;

	private:
		sdl::Texture m_texture;
		Point m_position;
		Size m_size;
	};
}

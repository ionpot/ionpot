#include "texture.hpp"

#include "point.hpp"
#include "size.hpp"

#include <sdl/font.hpp>
#include <sdl/texture.hpp>

#include <utility> // std::move

namespace ionpot::widget {
	Texture::Texture(sdl::Texture&& tx):
		Texture {std::move(tx), tx.query_size()}
	{}

	Texture::Texture(sdl::Texture&& tx, const sdl::Font& font):
		Texture {
			std::move(tx),
			Size {tx.query_size().width, font.line_height()}
		}
	{}

	Texture::Texture(sdl::Texture&& tx, Size size):
		m_texture {std::move(tx)},
		m_position {0},
		m_size {size}
	{}

	void
	Texture::position(Point p)
	{ m_position = p; }

	Point
	Texture::position() const
	{ return m_position; }

	void
	Texture::render() const
	{ m_texture.render(m_position, m_size); }

	Size
	Texture::size() const
	{ return m_size; }
}

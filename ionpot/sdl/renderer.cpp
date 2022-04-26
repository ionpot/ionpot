#include "renderer.hpp"

#include "exception.hpp"
#include "to.hpp"

#include <util/hexagon.hpp>
#include <util/point.hpp>
#include <util/rgb.hpp>
#include <util/rgba.hpp>
#include <util/size.hpp>

#include <SDL.h>

#include <array>
#include <memory> // std::shared_ptr

namespace ionpot::sdl {
	const Renderer::Flags
	Renderer::default_flags {
		SDL_RENDERER_ACCELERATED
		| SDL_RENDERER_PRESENTVSYNC
		| SDL_RENDERER_TARGETTEXTURE
	};

	Renderer::Renderer(std::shared_ptr<const Window> window, Flags flags):
		m_window {window},
		m_renderer {SDL_CreateRenderer(window->m_window, -1, flags)}
	{
		if (!m_renderer)
			throw Exception {};
	}

	Renderer::~Renderer()
	{
		if (m_renderer) {
			SDL_DestroyRenderer(m_renderer);
			m_renderer = NULL;
		}
	}

	Renderer::Renderer(Renderer&& from) noexcept:
		m_window {from.m_window},
		m_renderer {from.m_renderer}
	{
		from.m_renderer = NULL;
	}

	Renderer&
	Renderer::operator=(Renderer&& from) noexcept
	{
		m_window = from.m_window;
		m_renderer = from.m_renderer;
		from.m_renderer = NULL;
		return *this;
	}

	void
	Renderer::clear() const
	{
		auto err = SDL_RenderClear(m_renderer);
		if (err)
			throw Exception {};
	}

	void
	Renderer::draw_line(util::Point start, util::Point end) const
	{
		auto err = SDL_RenderDrawLine(
			m_renderer,
			start.x, start.y,
			end.x, end.y
		);
		if (err)
			throw Exception {};
	}

	void
	Renderer::draw_hex(const util::Hexagon& hex) const
	{
		std::array points = {
			to_point(hex.point1()),
			to_point(hex.point2()),
			to_point(hex.point3()),
			to_point(hex.point4()),
			to_point(hex.point5()),
			to_point(hex.point6()),
			to_point(hex.point1())
		};
		if (SDL_RenderDrawLines(m_renderer, points.data(), (int)points.size()))
			throw Exception {};
	}

	void
	Renderer::draw_rect(util::Point position, util::Size size) const
	{
		auto rect = to_rect(position, size);
		auto err = SDL_RenderDrawRect(m_renderer, &rect);
		if (err)
			throw Exception {};
	}

	void
	Renderer::present() const
	{
		SDL_RenderPresent(m_renderer);
	}

	util::Size
	Renderer::query_output_size() const
	{
		int width {0};
		int height {0};
		if (SDL_GetRendererOutputSize(m_renderer, &width, &height))
			throw Exception {};
		return {width, height};
	}

	void
	Renderer::reset_target() const
	{
		auto err = SDL_SetRenderTarget(m_renderer, NULL);
		if (err)
			throw Exception {};
	}

	void
	Renderer::reset_color() const
	{
		set_color(util::RGB::black);
	}

	void
	Renderer::set_blendmode(SDL_BlendMode mode) const
	{
		if (SDL_SetRenderDrawBlendMode(m_renderer, mode))
			throw Exception {};
	}

	void
	Renderer::set_color(const util::RGBA& color) const
	{
		auto err = SDL_SetRenderDrawColor(
			m_renderer,
			color.channels.red,
			color.channels.green,
			color.channels.blue,
			color.alpha
		);
		if (err)
			throw Exception {};
	}
}

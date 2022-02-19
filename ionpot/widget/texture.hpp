#pragma once

#include "box.hpp"
#include "size.hpp"

#include <memory> // std::shared_ptr
#include <utility> // std::move

namespace ionpot::widget {
	template<class T>
	class Texture : public Box {
	public:
		Texture(T&& tx):
			m_texture {std::move(tx)}
		{}

		void render() const
		{ m_texture.render(m_position); }

		Size size() const override
		{ return m_texture.size(); }

	private:
		T m_texture;
	};

	template<class T>
	class SharedTexture : public Box {
	public:
		SharedTexture(std::shared_ptr<T> tx):
			m_texture {tx}
		{}

		void render() const
		{ m_texture->render(m_position); }

		Size size() const override
		{ return m_texture->size(); }

	private:
		std::shared_ptr<T> m_texture;
	};
}

#pragma once

#include <optional>

namespace ionpot::util {
	template<class T>
	class Value {
	public:
		Value() = default;
		Value(T value):
			m_current {value},
			m_previous {value}
		{}

		std::optional<T>
		changed() const
		{
			if (m_current != m_previous)
				return m_current;
			return {};
		}

		T
		current() const
		{ return m_current; }

		T
		previous() const
		{ return m_previous; }

		void
		set_to_same()
		{ m_previous = m_current; }

		void
		operator=(T new_value)
		{
			m_previous = m_current;
			m_current = new_value;
		}

	private:
		T m_current;
		T m_previous;
	};
}

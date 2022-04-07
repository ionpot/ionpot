#pragma once

#include "cursor.hpp"

namespace ionpot::sdl {
	struct SystemCursor {
		struct Arrow : public Cursor { Arrow(); };
		struct Hand : public Cursor { Hand(); };
	};
}

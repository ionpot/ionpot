#pragma once

// base dir length defined in CMakeLists.txt
#define IONPOT_FILE ((char*)__FILE__ + IONPOT_BASE_DIR_LENGTH)

// declare move-constructor and move-assignment
#define IONPOT_DECLARE_MOVE(T)\
	T(T&&) noexcept;\
	T& operator=(T&&) noexcept;

// use default move-constructor and move-assignment
#define IONPOT_DEFAULT_MOVE(T)\
	T(T&&) = default;\
	T& operator=(T&&) = default;

// disable copy-constructor and copy-assignment
#define IONPOT_NO_COPY(T)\
	T(const T&) = delete;\
	T& operator=(const T&) = delete;

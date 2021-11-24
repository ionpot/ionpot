#pragma once

#include <exception>
#include <string>

#define IONPOT_EXCEPTION_AS(name, category)\
	struct name : public ionpot::util::Exception {\
		name(std::string text):\
			ionpot::util::Exception {category, text}\
		{};\
	};

#define IONPOT_EXCEPTION(category)\
	IONPOT_EXCEPTION_AS(Exception, category)

namespace ionpot::util {
	class Exception : public std::exception {
	public:
		std::string source;
		std::string text;
		const char * what() const throw()
		{
			return final_text.c_str();
		}
	protected:
		Exception(std::string source, std::string text):
			source {source},
			text {text},
			final_text {"(" + source + ") " + text}
		{}
	private:
		std::string final_text;
	};
}

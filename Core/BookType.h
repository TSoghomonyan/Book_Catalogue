#pragma once

#include <ostream>
#include <cstdint>

enum class BookType : uint8_t
{
	FICTION = 0,
	COOKBOOK,
	HOWTO
};

inline std::ostream& operator<<(std::ostream& os, BookType type)
{
	switch (type) {
	case BookType::FICTION:  os << "Fiction"; break;
	case BookType::COOKBOOK: os << "Cookbook"; break;
	case BookType::HOWTO:    os << "HowTo"; break;
	default: os << "Unknown"; break;
	}
	return os;
}
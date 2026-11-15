#pragma once

#include <cstdint>
#include <ostream>

enum class BookType : uint8_t 
{
	ANY = 0,
	FICTION,
	COOKBOOK,
	HOWTO
};

inline std::ostream& operator<<(std::ostream& os, const BookType& type)
{
	switch (type) {
	case BookType::ANY:		 os << "ANY"; break;
	case BookType::FICTION:	 os << "FICTION"; break;
	case BookType::COOKBOOK: os << "COOKBOOK"; break;
	case BookType::HOWTO:	 os << "HOWTO"; break;
	default:				 os << "UNKNOWN"; break;
	}
	return os;
}

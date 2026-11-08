#pragma once

#include <ostream>
#include <cstdint>

enum class Genre : uint8_t 
{
	ADVENTURE = 0,
	CLASSICS,
	DETECTIVE,
	FANTASY,
	HISTORIC,
	HORROR,
	ROMANCE,
	SCIFI
};

inline std::ostream& operator<<(std::ostream& os, Genre genre)
{
	switch (genre) {
	case Genre::ADVENTURE:	os << "ADVENTURE"; break;
	case Genre::CLASSICS:	os << "CLASSICS"; break;
	case Genre::DETECTIVE:	os << "DETECTIVE"; break;
	case Genre::FANTASY:	os << "FANTASY"; break;
	case Genre::HISTORIC:	os << "HISTORIC"; break;
	case Genre::HORROR:		os << "HORROR"; break;
	case Genre::ROMANCE:	os << "ROMANCE"; break;
	case Genre::SCIFI:		os << "SCIFI"; break;
	default:				os << "UNKNOWN"; break;
	}
	return os;
}
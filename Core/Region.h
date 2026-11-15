#pragma once

#include <cstdint>
#include <ostream>

enum class Region : uint8_t 
{
	NONE = 0,
	CHINA,
	FRANCE,
	INDIA,
	ITALY,
	MEXICO,
	US
};

inline std::ostream& operator<<(std::ostream& os, Region region)
{
	switch (region) {
	case Region::NONE:	 os << "NONE"; break;
	case Region::CHINA:	 os << "CHINA"; break;
	case Region::INDIA:	 os << "INDIA"; break;
	case Region::FRANCE: os << "FRANCE"; break;
	case Region::MEXICO: os << "MEXICO"; break;
	case Region::US:	 os << "US"; break;
	case Region::ITALY:	 os << "ITALY"; break;
	default:			 os << "UNKNOWN"; break;
	}
	return os;
}

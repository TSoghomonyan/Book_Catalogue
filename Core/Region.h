#pragma once

#include <ostream>
#include <cstdint>

enum class Region : uint8_t 
{
	CHINA = 0,
	FRANCE,
	INDIA,
	ITALY,
	MEXICO,
	US
};

inline std::ostream& operator<<(std::ostream& os, Region region)
{
	switch (region) {
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

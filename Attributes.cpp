#include "Attributes.h"

std::ostream& operator<<(std::ostream& os, Genre genre)
{
	switch (genre) {
	case Genre::NONE:		os << "NONE"; break;
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

std::ostream& operator<<(std::ostream& os, Region region)
{
	switch (region) {
	case Region::NONE:	 os << "NONE"; break;
	case Region::CHINA:	 os << "CHINA"; break;
	case Region::INDIA:	 os << "INDIA"; break;
	case Region::FRANCE: os << "FRANCE"; break;
	case Region::US:	 os << "US"; break;
	case Region::ITALY:	 os << "ITALY"; break;
	default:			 os << "UNKNOWN"; break;
	}
	return os;
}

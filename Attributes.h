#pragma once

#include <cstdint>
#include <ostream>
#include <string>

enum class Genre : uint8_t {
	NONE = 0,
	ADVENTURE,
	CLASSICS,
	DETECTIVE,
	FANTASY,
	HISTORIC,
	HORROR,
	ROMANCE,
	SCIFI
};

std::ostream& operator<<(std::ostream& os, Genre genre);

enum class Region : uint8_t {
	NONE = 0,
	CHINA,
	FRANCE,
	INDIA,
	ITALY,
	MEXICO,
	US
};

std::ostream& operator<<(std::ostream& os, Region region);

struct Attributes {
	Genre m_genre = Genre::NONE;
	Region m_region = Region::NONE;
	uint16_t m_year = 0;
	std::string m_title;
	std::string m_name;		/// author's first name
	std::string m_surname;	/// author's last name
};

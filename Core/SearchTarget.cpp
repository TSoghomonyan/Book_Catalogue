#include "SearchTarget.h"

std::ostream& operator<<(std::ostream& os, const book_type& type)
{
	switch (type) {
	case book_type::ANY:		os << "ANY"; break;
	case book_type::FICTION:	os << "FICTION"; break;
	case book_type::COOKBOOK:	os << "COOKBOOK"; break;
	case book_type::HOWTO:		os << "HOWTO"; break;
	default: os << "UNKNOWN"; break;
	}
	return os;
}

std::ostream& operator<<(std::ostream& os, const SearchTarget& target)
{
	os << "Type: " << target.type << ", Attributes: {"
		<< "Genre: " << target.attributes.m_genre
		<< ", Region: " << target.attributes.m_region
		<< ", Year: " << target.attributes.m_year
		<< ", Subject: " << target.attributes.m_subject
		<< ", Title: " << target.attributes.m_title
		<< ", Name: " << target.attributes.m_name
		<< ", Surname: " << target.attributes.m_surname
		<< "}";
	return os;
}

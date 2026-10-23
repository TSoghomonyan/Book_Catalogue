#include "Book.h"

std::ostream& operator<<(std::ostream& os, Genre genre)
{
	switch (genre) {
	case NONE: os << "NONE"; break;
	case ADVENTURE: os << "ADVENTURE"; break;
	case CLASSICS: os << "CLASSICS"; break;
	case DETECTIVE: os << "DETECTIVE"; break;
	case FANTASY: os << "FANTASY"; break;
	case HISTORIC: os << "HISTORIC"; break;
	case HORROR: os << "HORROR"; break;
	case ROMANCE: os << "ROMANCE"; break;
	case SCIFI: os << "SCIFI"; break;
	default: os << "UNKNOWN"; break;
	}
	return os;
}

std::ostream& operator<<(std::ostream& os, const Book& attributes)
{
	os << "{TITLE: '" << attributes.title() << "', "
		<< "NAME: '" << attributes.name() << "', "
		<< "SURNAME: '" << attributes.surname() << "', "
		<< "YEAR: " << attributes.year() << ", "
		<< "GENRE: " << attributes.genre() << "}";
	return os;
}

bool Book::matches(const Book& target) const
{
	bool check = true;
	check &= target.title().empty() || checkStrings(m_title, target.title());
	check &= target.name().empty() || checkStrings(m_name, target.name());
	check &= target.surname().empty() || checkStrings(m_surname, target.surname());
	check &= 0 == target.year() || m_year == target.year();
	check &= NONE == target.genre() || m_genre == target.genre();
	return check;
}

bool Book::checkStrings(const std::string& str1, const std::string& str2) const
{
	if (str1.size() != str2.size()) {
		return false;
	}

	for (size_t i = 0; i < str1.size(); ++i) {
		if (tolower(str1[i]) != tolower(str2[i])) {
			return false;
		}
	}

	return true;
}

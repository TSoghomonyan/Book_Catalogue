#pragma once

#include "BookType.h"
#include "Genre.h"
#include "Region.h"

#include <cstdint>
#include <ostream>
#include <string>

struct  Attributes final { // it's not designed for inheritance
	inline bool isMatch(const Attributes& target) const
	{
		bool match = true;
		match &= (target.m_type == BookType::ANY) || (target.m_type == m_type);
		match &= (target.m_genre == Genre::NONE) || (target.m_genre == m_genre);
		match &= (target.m_region == Region::NONE) || (target.m_region == m_region);
		match &= (target.m_year == 0) || (target.m_year == m_year);
		match &= (target.m_subject.empty()) || checkStrings(target.m_subject, m_subject);
		match &= (target.m_title.empty()) || checkStrings(target.m_title, m_title);
		match &= (target.m_name.empty()) || checkStrings(target.m_name, m_name);
		match &= (target.m_surname.empty()) || checkStrings(target.m_surname, m_surname);
		return match;
	}

	friend std::ostream& operator<<(std::ostream& os, const Attributes& attributes);

	BookType m_type = BookType::ANY;	// book's type
	Genre m_genre = Genre::NONE;		// book's genre
	Region m_region = Region::NONE;		// book's region of origin
	uint16_t m_year = 0;				// book's publication year
	std::string m_subject;				// book's subject
	std::string m_title;				// book's title
	std::string m_name;					// author's first name
	std::string m_surname;				// author's last name

private:
	// case insensitive string comparison
	inline bool checkStrings(const std::string& str1, const std::string& str2) const
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
};

inline std::ostream& operator<<(std::ostream& os, const Attributes& a)
{
	os << "{ Type: " << a.m_type;
	if (a.m_genre != Genre::NONE)	os << ", Genre: " << a.m_genre;
	if (a.m_region != Region::NONE) os << ", Region: " << a.m_region;
	if (a.m_year != 0)				os << ", Year: " << a.m_year;
	if (!a.m_subject.empty())		os << ", Subject: " << a.m_subject;
	if (!a.m_title.empty())			os << ", Title: " << a.m_title;
	if (!a.m_name.empty())			os << ", Name: " << a.m_name;
	if (!a.m_surname.empty())		os << ", Surname: " << a.m_surname;
	os << " }";
	return os;
}
#pragma once

#include <cstdint>
#include <ostream>
#include <string>

enum Genre : uint8_t {
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

class Book {
public:
	Book(
		const Genre genre,
		const uint16_t year,
		const std::string& title,
		const std::string& name,
		const std::string& surname)
		: m_genre(genre)
		, m_year(year)
		, m_title(title)
		, m_name(name)
		, m_surname(surname)
	{}

	inline const Genre genre() const { return m_genre; }
	inline const uint16_t year() const { return m_year; }
	inline const std::string& title() const { return m_title; }
	inline const std::string& name() const { return m_name; }
	inline const std::string& surname() const { return m_surname; }

	bool matches(const Book& target) const;
	friend std::ostream& operator<<(std::ostream& os, const Book& attributes);

private:
	// case insesitive
	bool checkStrings(const std::string& str1, const std::string& str2) const;

private:
	Genre m_genre = NONE;
	uint16_t m_year = 0;
	std::string m_title;
	std::string m_name;		/// author's first name
	std::string m_surname;	/// author's last name
};
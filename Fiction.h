#pragma once

#include "Book.h"

#include <string>

class Fiction : public Book {
public:
	Fiction(
		const Genre genre,
		const uint16_t year,
		const std::string& title,
		const std::string& name,
		const std::string& surname)
	{
		m_type = book_type::FICTION;
		m_attributes.m_genre = genre;
		m_attributes.m_year = year;
		m_attributes.m_title = title;
		m_attributes.m_name = name;
		m_attributes.m_surname = surname;
	}

	Fiction(const Fiction&) = default;
	Fiction(Fiction&&) = default;

	Fiction& operator=(const Fiction&) = default;
	Fiction& operator=(Fiction&&) = default;

	~Fiction() override = default;

	Genre genre() const;
	const uint16_t year() const;
	const std::string& title() const;
	const std::string& name() const;
	const std::string& surname() const;

	bool matches(const Book* target) const override;
	std::ostream& print(std::ostream& os) const override;
};

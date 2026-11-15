#pragma once

#include "Core/Book.h"

#include <string>

class Fiction : public Book {
public:
	Fiction(
		const Genre genre,
		const uint16_t year,
		const std::string& title,
		const std::string& name,
		const std::string& surname)
		: Book(Attributes{
			.m_type = BookType::FICTION,
			.m_genre = genre,
			.m_year = year,
			.m_title = title,
			.m_name = name,
			.m_surname = surname })
	{}

	Genre genre() const
	{
		return m_attributes.m_genre;
	}

	uint16_t year() const
	{
		return m_attributes.m_year;
	}
};

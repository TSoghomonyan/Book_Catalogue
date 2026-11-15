#pragma once

#include "BookType.h"
#include "Genre.h"
#include "Region.h"
#include "Attributes.h"
#include "Book.h"

#include <cstdint>
#include <string>

inline Book makeFiction(Genre genre,
						uint16_t year,
						const std::string& title,
						const std::string& author_name,
						const std::string& author_surname)
{
	Attributes attributes;
	attributes.m_type = BookType::FICTION;
	attributes.m_genre = genre;
	attributes.m_year = year;
	attributes.m_title = title;
	attributes.m_name = author_name;
	attributes.m_surname = author_surname;
	return Book(std::move(attributes));
}

inline Book makeCookBook(Region region,
						 const std::string& title,
						 const std::string& author_name,
						 const std::string& author_surname)
{
	Attributes attributes;
	attributes.m_type = BookType::COOKBOOK;
	attributes.m_region = region;
	attributes.m_title = title;
	attributes.m_name = author_name;
	attributes.m_surname = author_surname;
	return Book(std::move(attributes));
}

inline Book makeHowTo(const std::string& subject,
					  const std::string& title,
					  const std::string& author_name,
					  const std::string& author_surname)
{
	Attributes attributes;
	attributes.m_type = BookType::HOWTO;
	attributes.m_subject = subject;
	attributes.m_title = title;
	attributes.m_name = author_name;
	attributes.m_surname = author_surname;
	return Book(std::move(attributes));
}
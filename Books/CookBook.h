#pragma once

#include "Core/Book.h"

class CookBook : public Book {
public:
	CookBook(
		const Region region,
		const std::string& title,
		const std::string& name,
		const std::string& surname)
		: Book(Attributes{
			.m_type = BookType::COOKBOOK,
			.m_region = region,
			.m_title = title,
			.m_name = name,
			.m_surname = surname })
	{}

	Region region() const
	{
		return m_attributes.m_region;
	}
};

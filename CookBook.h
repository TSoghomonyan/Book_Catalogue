#pragma once

#include "Book.h"

class CookBook : public Book {
public:
	CookBook(
		const Region region,
		const uint16_t year,
		const std::string& title,
		const std::string& name,
		const std::string& surname)
	{
		m_type = book_type::COOKBOOK;
		m_attributes.m_region = region;
		m_attributes.m_year = year;
		m_attributes.m_title = title;
		m_attributes.m_name = name;
		m_attributes.m_surname = surname;
	}

	CookBook(const CookBook&) = default;
	CookBook(CookBook&&) = default;

	CookBook& operator=(const CookBook&) = default;
	CookBook& operator=(CookBook&&) = default;

	~CookBook() override = default;

	Region region() const;
	const uint16_t year() const;
	const std::string& title() const;
	const std::string& name() const;
	const std::string& surname() const;

	bool matches(const Book* target) const override;
	std::ostream& print(std::ostream& os) const override;
};

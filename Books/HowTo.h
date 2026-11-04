#pragma once

#include "Core/Book.h"

class HowTo : public Book {
public:
	HowTo(
		const std::string& subject,
		const std::string& title,
		const std::string& name,
		const std::string& surname)
	{
		m_type = book_type::HOWTO;
		m_attributes.m_subject = subject;
		m_attributes.m_title = title;
		m_attributes.m_name = name;
		m_attributes.m_surname = surname;
	}

	HowTo(const HowTo&) = default;
	HowTo(HowTo&&) = default;

	HowTo& operator=(const HowTo&) = default;
	HowTo& operator=(HowTo&&) = default;

	~HowTo() override = default;

	const std::string& subject() const;

private:
	bool matchesOwn(const SearchTarget& target) const override;
	std::ostream& print(std::ostream& os) const override;
};
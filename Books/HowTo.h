#pragma once

#include "Core/Book.h"

class HowTo : public Book {
public:
	HowTo(
		const std::string& subject,
		const std::string& title,
		const std::string& name,
		const std::string& surname)
		: Book(Attributes{
			.m_type = BookType::HOWTO,
			.m_subject = subject,
			.m_title = title,
			.m_name = name,
			.m_surname = surname })
	{}

	const std::string& subject() const
	{
		return m_attributes.m_subject;
	}
};
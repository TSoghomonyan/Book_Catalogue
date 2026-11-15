#pragma once

#include "BookType.h"
#include "Genre.h"
#include "Region.h"
#include "Attributes.h"

#include <ostream>
#include <string>

class Book {
public:
	explicit Book(Attributes attributes) : m_attributes(std::move(attributes)) {}
	Book(const Book&) = default;
	Book(Book&&) = default;

	Book& operator=(const Book&) = default;
	Book& operator=(Book&&) = default;

	virtual ~Book() = default;

	bool matches(const Attributes& target) const;

	BookType type() const;

	const std::string& title() const;
	const std::string& name() const;
	const std::string& surname() const;

	friend std::ostream& operator<<(std::ostream& os, const Book& book);

protected:
	Attributes m_attributes;
};

inline std::ostream& operator<<(std::ostream& os, const Book& book)
{
	return os << book.m_attributes;
}

#pragma once

#include "Attributes.h"
#include "SearchTarget.h"

class Book {
public:
	Book() = default;
	Book(const Book&) = default;
	Book(Book&&) = default;

	Book& operator=(const Book&) = default;
	Book& operator=(Book&&) = default;

	virtual ~Book() = default;

	virtual std::ostream& print(std::ostream& os) const = 0;
	
	bool matches(const SearchTarget& target) const;

	book_type type() const;

	const std::string& title() const;
	const std::string& name() const;
	const std::string& surname() const;

protected:
	const Attributes& attributes() const;
	
	// case insesitive
	bool checkStrings(const std::string& str1, const std::string& str2) const;

	virtual bool matchesOwn(const SearchTarget& target) const = 0;

protected:
	book_type m_type = book_type::ANY;
	Attributes m_attributes = {};
};

inline std::ostream& operator<<(std::ostream& os, const Book& book)
{
	return book.print(os);
}

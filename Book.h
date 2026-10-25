#pragma once

#include "Attributes.h"

enum class book_type : uint8_t {
	NONE = 0,
	FICTION,
	COOKBOOK
};

class Book {
public:
	Book() = default;
	Book(const Book&) = default;
	Book(Book&&) = default;

	Book& operator=(const Book&) = default;
	Book& operator=(Book&&) = default;

	virtual ~Book() = default;

	virtual bool matches(const Book* target) const = 0;
	virtual std::ostream& print(std::ostream& os) const = 0;

	book_type type() const;
	const Attributes& attributes() const;

protected:
	// case insesitive
	bool checkStrings(const std::string& str1, const std::string& str2) const;

protected:
	book_type m_type = book_type::NONE;
	Attributes m_attributes = {};
};

inline std::ostream& operator<<(std::ostream& os, const Book& book)
{
	return book.print(os);
}

#pragma once

#include "BookType.h"
#include "Genre.h"
#include "Region.h"
#include "Attributes.h"

#include <ostream>
#include <string>

class Book final {
public:
	explicit Book(Attributes attributes) : m_attributes(std::move(attributes)) {}
	
	bool matches(const Attributes& target) const
	{
		return m_attributes.isMatch(target);
	}

	const Attributes& attributes() const { return m_attributes; }

	friend std::ostream& operator<<(std::ostream& os, const Book& book);

private:
	Attributes m_attributes;
};

inline std::ostream& operator<<(std::ostream& os, const Book& book)
{
	return os << book.m_attributes;
}

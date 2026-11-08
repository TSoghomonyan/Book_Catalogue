#pragma once

#include "Attributes.h"
#include "Key.h"

#include <variant>
#include <string>
#include <ostream>

class Book
{
public:
	inline Book(Attributes attributes) : m_attributes(std::move(attributes)) {}

	inline const Attributes& getAttributes() const { return m_attributes; }

	inline bool isMatching(const Attributes& target) const
	{
		return m_attributes.isMatching(target);
	}

	inline
	friend std::ostream& operator<<(std::ostream& os, const Book& attributes)
	{
		os << attributes.m_attributes;
		return os;
	}

private:
	Attributes m_attributes;
};

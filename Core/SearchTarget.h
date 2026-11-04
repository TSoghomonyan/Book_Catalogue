#pragma once

#include "Attributes.h"

#include <ostream>

enum class book_type : uint8_t {
	ANY = 0,
	FICTION,
	COOKBOOK,
	HOWTO
};

std::ostream& operator<<(std::ostream& os, const book_type& type);

struct SearchTarget {
	book_type type = book_type::ANY;
	Attributes attributes = {};
};

std::ostream& operator<<(std::ostream& os, const SearchTarget& target);
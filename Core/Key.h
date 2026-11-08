#pragma once

#include "BookType.h"
#include "Genre.h"
#include "Region.h"

#include <ostream>
#include <cstdint>

enum class Key : uint8_t 
{
	BOOK_TYPE = 0,
	AUTHOR_NAME,
	AUTHOR_SURNAME,
	TITLE,
	SUBJECT,
	GENRE,
	REGION,
	YEAR
};

inline std::ostream& operator<<(std::ostream& os, Key key)
{
	switch (key) {
	case Key::BOOK_TYPE:	  os << "Book type"; break;
	case Key::AUTHOR_NAME:	  os << "Author name"; break;
	case Key::AUTHOR_SURNAME: os << "Author surname"; break;
	case Key::TITLE:		  os << "Title"; break;
	case Key::SUBJECT:		  os << "Subject"; break;
	case Key::GENRE:		  os << "Genre"; break;
	case Key::REGION:		  os << "Region"; break;
	case Key::YEAR:			  os << "Year"; break;
	default: os << "Unknown"; break;
	}
	return os;
}

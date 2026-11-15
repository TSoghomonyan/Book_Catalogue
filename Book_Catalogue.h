#pragma once

#include "Core/Book.h"

#include <list>
#include <memory>

class BookCatalogue {
public:
	void insertBook(Book book);
	std::list<const Book *> find(const Attributes& target) const;

private:
	std::list<Book> m_catalogue;
};

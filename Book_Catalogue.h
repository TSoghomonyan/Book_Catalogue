#pragma once

#include "Core/Book.h"

#include <list>
#include <memory>

using std::string;

class BookCatalogue {
public:
	void insertBook(std::unique_ptr<Book> book);
	std::list<const Book *> find(const SearchTarget &target) const;

private:
	std::list<std::unique_ptr<Book>> m_catalogue;
};

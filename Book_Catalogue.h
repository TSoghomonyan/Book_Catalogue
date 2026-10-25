#pragma once

#include "Fiction.h"

#include <list>

using std::string;

class BookCatalogue {
private:
	
	//using std::list<Book>;
	//using std::unordered_map<Book, int>;
public:
	void insertBook(std::unique_ptr<Book> book);
	std::list<const Book *> find(const Book &target);

private:
	std::list<std::unique_ptr<Book>> m_catalogue;
};

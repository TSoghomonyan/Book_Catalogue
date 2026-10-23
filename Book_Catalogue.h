#pragma once

//#include <iostream>

#include "Book.h"
#include <string>
#include <list>
#include <unordered_map>

using std::string;

class BookCatalogue {
private:
	
	//using std::list<Book>;
	//using std::unordered_map<Book, int>;
public:
	void insertBook(const Book &book);
	std::list<Book> find(const Book &target);

private:
	std::list<Book> m_catalogue;
};

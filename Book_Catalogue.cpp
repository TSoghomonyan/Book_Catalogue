#include "Book_Catalogue.h"

void BookCatalogue::insertBook(const Book &book)
{
	m_catalogue.push_back(book);
}

std::list<Book> BookCatalogue::find(const Book &target)
{
	std::list<Book> matches;

	for (auto it = m_catalogue.begin(); it != m_catalogue.end(); ++it) {
		if (it->matches(target)) {
			matches.push_back(*it);
		}
	}

	return matches;
}

#include "Book_Catalogue.h"

void BookCatalogue::insertBook(std::unique_ptr<Book> book)
{
	m_catalogue.push_back(std::move(book));
}

std::list<const Book *> BookCatalogue::find(const Book &target)
{
	std::list<const Book *> matches;

	for (const auto& book : m_catalogue) {
		if (book->matches(&target)) {
			matches.push_back(book.get());
		}
	}

	return matches;
}

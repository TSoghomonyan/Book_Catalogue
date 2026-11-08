#include "Book_Catalogue.h"

void BookCatalogue::insertBook(Book book)
{
	m_catalogue.push_back(std::move(book));
}

std::list<const Book *> BookCatalogue::find(const Attributes& target) const
{
	std::list<const Book *> matches;

	for (const auto& book : m_catalogue) {
		if (book.isMatching(target)) {
			matches.push_back(&book);
		}
	}

	return matches;
}

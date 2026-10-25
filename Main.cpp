#include <iostream>

#include "Book_Catalogue.h"

int main() {
	BookCatalogue catalogue;

	catalogue.insertBook(std::make_unique<Fiction>(Genre::CLASSICS, 1925, "The Great Gatsby", "F. Scott", "Fitzgerald"));
	catalogue.insertBook(std::make_unique<Fiction>(Genre::ADVENTURE, 2001, "Life of Pi", "Yann", "Martel"));
	catalogue.insertBook(std::make_unique<Fiction>(Genre::ADVENTURE, 1903, "The Call of the Wild", "Jack", "London"));
	catalogue.insertBook(std::make_unique<Fiction>(Genre::CLASSICS, 1960, "To Kill a Mockingbird", "Harper", "Lee"));
	catalogue.insertBook(std::make_unique<Fiction>(Genre::CLASSICS, 1868, "Little Women", "Louisa", "Alcott"));
	catalogue.insertBook(std::make_unique<Fiction>(Genre::DETECTIVE, 1892, "The Adventures of Sherlock Holmes", "Conan", "Doyle"));
	catalogue.insertBook(std::make_unique<Fiction>(Genre::DETECTIVE, 1939, "And Then There Were None", "Agatha", "Christie"));
	catalogue.insertBook(std::make_unique<Fiction>(Genre::HORROR, 1974, "Carrie", "Stephen", "King"));
	catalogue.insertBook(std::make_unique<Fiction>(Genre::HORROR, 1986, "It: A Novel", "Stephen", "King"));
	catalogue.insertBook(std::make_unique<Fiction>(Genre::HORROR, 1818, "Frankenstein", "Mary", "Shelley"));
	catalogue.insertBook(std::make_unique<Fiction>(Genre::SCIFI, 1968, "2001: A Space Odyssey", "Arthur", "Clarke"));
	catalogue.insertBook(std::make_unique<Fiction>(Genre::SCIFI, 1985, "Ender's Game", "Orson", "Card"));

	std::list<Fiction> findBooks = {
		{Genre::NONE, 0, "The Great Gatsby", "", "" },
		{Genre::DETECTIVE, 0,"", "", "" },
		{Genre::NONE, 1960, "", "", "" },
		{Genre::HORROR, 1818, "", "", "" },
		{Genre::SCIFI, 0, "", "", "King" },
		{Genre::ROMANCE, 0, "", "", "" },
		{Genre::HORROR, 0, "", "", "King" },
		{Genre::NONE, 0, "1984", "George", "Orwell"},
		{Genre::NONE, 0, "life of PI", "", ""},
		{Genre::NONE, 0, "Life of PI", "Yann", "Martel"},
		{Genre::NONE, 0, "", "", ""},
		{Genre::NONE, 0,  "", "Stephen", "King"},
		{Genre::NONE, 0,  "", "", "Shelley" },
		{Genre::NONE, 0,  "Ender's Game", "", "Card" }
	};

	for (auto it = findBooks.begin(); it != findBooks.end(); ++it) {
		auto matches = catalogue.find(*it);
		std::cout << "Searching for: "<< *it << std::endl;

		if (matches.empty()) {
			std::cout << "No matches found." << std::endl;
		} else {
			std::cout << "Matches found:" << std::endl;

			for (auto book : matches) {
				std::cout << *book << std::endl;
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	return 0;
}

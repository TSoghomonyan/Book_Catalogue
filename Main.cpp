#include <iostream>

#include "Book_Catalogue.h"

int main() {
	BookCatalogue catalogue;

	catalogue.insertBook({ CLASSICS, 1925, "The Great Gatsby", "F. Scott", "Fitzgerald" });
	catalogue.insertBook({ ADVENTURE, 2001, "Life of Pi", "Yann", "Martel" });
	catalogue.insertBook({ ADVENTURE, 1903, "The Call of the Wild", "Jack", "London" });
	catalogue.insertBook({ CLASSICS, 1960, "To Kill a Mockingbird", "Harper", "Lee" });
	catalogue.insertBook({ CLASSICS, 1868, "Little Women", "Louisa", "Alcott" });
	catalogue.insertBook({ DETECTIVE, 1892, "The Adventures of Sherlock Holmes", "Conan", "Doyle" });
	catalogue.insertBook({ DETECTIVE, 1939, "And Then There Were None", "Agatha", "Christie" });
	catalogue.insertBook({ HORROR, 1974, "Carrie", "Stephen", "King" });
	catalogue.insertBook({ HORROR, 1986, "It: A Novel", "Stephen", "King" });
	catalogue.insertBook({ HORROR, 1818, "Frankenstein", "Mary", "Shelley" });
	catalogue.insertBook({ SCIFI, 1968, "2001: A Space Odyssey", "Arthur", "Clarke" });
	catalogue.insertBook({ SCIFI, 1985, "Ender's Game", "Orson", "Card" });

	std::list<Book> findBooks = {
		{NONE, 0, "The Great Gatsby", "", "" },
		{DETECTIVE, 0,"", "", "" },
		{NONE, 1960, "", "", "" },
		{HORROR, 1818, "", "", "" },
		{SCIFI, 0, "", "", "King" },
		{ROMANCE, 0, "", "", "" },
		{HORROR, 0, "", "", "King" },
		{NONE, 0, "1984", "George", "Orwell"},
		{NONE, 0, "life of PI", "", ""},
		{NONE, 0, "Life of PI", "Yann", "Martel"},
		{NONE, 0, "", "", ""},
		{NONE, 0,  "", "Stephen", "King"},
		{NONE, 0,  "", "", "Shelley" },
		{NONE, 0,  "Ender's Game", "", "Card" }
	};

	for (auto it = findBooks.begin(); it != findBooks.end(); ++it) {
		std::list<Book> matches = catalogue.find(*it);
		std::cout << "Searching for: "<< *it << std::endl;

		if (matches.empty()) {
			std::cout << "No matches found." << std::endl;
		} else {
			std::cout << "Matches found:" << std::endl;

			for (auto matchIt = matches.begin(); matchIt != matches.end(); ++matchIt) {
				std::cout << *matchIt << std::endl;
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	return 0;
}

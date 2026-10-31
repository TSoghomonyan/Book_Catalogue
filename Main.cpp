#include <iostream>

#include "Book_Catalogue.h"
#include "Fiction.h"
#include "CookBook.h"

void findBooks(const BookCatalogue& catalogue, std::list<SearchTarget> &targets) {
	for (auto it = targets.begin(); it != targets.end(); ++it) {
		auto matches = catalogue.find(*it);
		std::cout << "Searching for: " << *it << std::endl;

		if (matches.empty()) {
			std::cout << "No matches found." << std::endl;
		}
		else {
			std::cout << "Matches found:" << std::endl;

			for (auto book : matches) {
				std::cout << *book << std::endl;
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
}

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
	catalogue.insertBook(std::make_unique<CookBook>(Region::CHINA, "The Woks of Life", "Bill", "Leung"));
	catalogue.insertBook(std::make_unique<CookBook>(Region::CHINA, "Chinese Cooking for Dummies", "Martin", "Yan"));
	catalogue.insertBook(std::make_unique<CookBook>(Region::FRANCE, "Mastering the Art of French Cooking", "Julia", "Child"));
	catalogue.insertBook(std::make_unique<CookBook>(Region::INDIA, "Made in India", "Meera", "Sodha"));
	catalogue.insertBook(std::make_unique<CookBook>(Region::FRANCE, "The Lee Bros. Southern Cookbook", "Matt", "Lee"));

	std::list<SearchTarget> targets1 = {
		{book_type::FICTION, { Genre::NONE, Region::NONE, 0, "The Great Gatsby", "", "" } },
		{book_type::FICTION, { Genre::DETECTIVE, Region::NONE, 0, "", "", "" } },
		{book_type::FICTION, { Genre::NONE, Region::NONE, 1960, "", "", "" } },
		{book_type::FICTION, { Genre::HORROR, Region::NONE, 1818, "", "", "" } },
		{book_type::FICTION, { Genre::SCIFI, Region::NONE, 0, "", "", "King" } },
		{book_type::FICTION, { Genre::ROMANCE, Region::NONE, 0, "", "", "" } },
		{book_type::FICTION, { Genre::HORROR, Region::NONE, 0, "", "", "King" } },
		{book_type::FICTION, { Genre::NONE, Region::NONE, 0, "1984", "George", "Orwell"} },
		{book_type::FICTION, { Genre::NONE, Region::NONE, 0, "life of PI", "", ""} },
		{book_type::FICTION, { Genre::NONE, Region::NONE, 0, "Life of PI", "Yann", "Martel"} },
		{book_type::FICTION, { Genre::NONE, Region::NONE, 0, "", "", ""} },
		{book_type::FICTION, { Genre::NONE, Region::NONE, 0, "", "Stephen", "King"} },
		{book_type::FICTION, { Genre::NONE, Region::NONE, 0, "", "", "Shelley" } },
		{book_type::FICTION, { Genre::NONE, Region::NONE, 0, "Ender's Game", "", "Card" } }
	};

	std::list<SearchTarget> targets2 = {
		{ book_type::COOKBOOK, {Genre::NONE, Region::CHINA} },
		{ book_type::ANY, {Genre::NONE, Region::CHINA} },
		{ book_type::ANY, {Genre::NONE, Region::NONE, 0, "", "", "Lee"}},
		{ book_type::COOKBOOK, { Genre::NONE, Region::NONE, 0, "", "", "Lee" } },
		{ book_type::FICTION, { Genre::NONE, Region::NONE, 0, "", "", "Lee" } },
		{ book_type::ANY, { Genre::HORROR, Region::NONE, 0, "", "", "" } },
		{ book_type::ANY, { Genre::NONE, Region::ITALY} },
		{ book_type::COOKBOOK, {} },
		{ book_type::ANY, {} }
	};

	findBooks(catalogue, targets1);	
	findBooks(catalogue, targets2);

	return 0;
}

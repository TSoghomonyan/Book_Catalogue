#include <iostream>

#include "Book_Catalogue.h"
#include "Books/Fiction.h"
#include "Books/CookBook.h"
#include "Books/HowTo.h"

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
	catalogue.insertBook(std::make_unique<CookBook>(Region::US, "The Lee Bros. Southern Cookbook", "Matt", "Lee"));
	catalogue.insertBook(std::make_unique<HowTo>("programming", "Clean Code", "Robert", "Martin"));
	catalogue.insertBook(std::make_unique<HowTo>("programming", "The Pragmatic Programmer", "Andrew", "Hunt"));
	catalogue.insertBook(std::make_unique<HowTo>("gardening", "The Vegetable Gardener's Bible", "Edward", "Smith"));
	catalogue.insertBook(std::make_unique<HowTo>("communication", "How to Win Friends and Influence People", "Dale", "Carnegie"));
	catalogue.insertBook(std::make_unique<HowTo>("writing", "On Writing", "Stephen", "King"));

	std::list<SearchTarget> targets1 = {
		{ book_type::FICTION, { .m_title = "The Great Gatsby" } },
		{ book_type::FICTION, { .m_genre = Genre::DETECTIVE } },
		{ book_type::FICTION, { .m_year = 1960 } },
		{ book_type::FICTION, { .m_genre = Genre::HORROR, .m_year = 1818 } },
		{ book_type::FICTION, { .m_genre = Genre::SCIFI, .m_surname = "King" } },
		{ book_type::FICTION, { .m_genre = Genre::ROMANCE } },
		{ book_type::FICTION, { .m_genre = Genre::HORROR, .m_surname = "King" } },
		{ book_type::FICTION, { .m_title = "1984", .m_name = "George", .m_surname = "Orwell" } },
		{ book_type::FICTION, { .m_title = "life of PI" } },
		{ book_type::FICTION, { .m_title = "Life of PI", .m_name = "Yann", .m_surname = "Martel"} },
		{ book_type::FICTION, {} },
		{ book_type::FICTION, { .m_name = "Stephen", .m_surname = "King"} },
		{ book_type::FICTION, { .m_surname = "Shelley" } },
		{ book_type::FICTION, { .m_title = "Ender's Game", .m_surname = "Card" } }
	};

	std::list<SearchTarget> targets2 = {
		{ book_type::COOKBOOK, { .m_region = Region::CHINA} },
		{ book_type::ANY, { .m_region = Region::CHINA} },
		{ book_type::ANY, { .m_surname = "Lee"}},
		{ book_type::COOKBOOK, { .m_surname = "Lee" } },
		{ book_type::FICTION, { .m_surname = "Lee" } },
		{ book_type::ANY, { .m_genre = Genre::HORROR } },
		{ book_type::ANY, { .m_region = Region::ITALY} },
		{ book_type::COOKBOOK, {} },
		{ book_type::ANY, {} }
	};

	std::list<SearchTarget> targets3 = {
		{ book_type::HOWTO, { .m_subject = "programming" } },
		{ book_type::ANY, { .m_subject = "PROGRAMMING" } },
		{ book_type::ANY, { .m_surname = "King"} },
		{ book_type::HOWTO, { .m_surname = "King" } },
		{ book_type::ANY, { .m_name = "Martin" } },
		{ book_type::ANY, { .m_surname = "Martin" } },
		{ book_type::ANY,{ .m_genre = Genre::HORROR } },
		{ book_type::ANY, { .m_region = Region::CHINA } },
		{ book_type::ANY, { .m_subject = "cooking" } },
		{ book_type::HOWTO, {} }
	};

	std::cout << "<------  FIRST TEST CASE  ------>" << std::endl;
	findBooks(catalogue, targets1);	
	std::cout << "<------  SECOND TEST CASE  ------>" << std::endl;
	findBooks(catalogue, targets2);
	std::cout << "<------  THIRD TEST CASE  ------>" << std::endl;
	findBooks(catalogue, targets3);	

	return 0;
}

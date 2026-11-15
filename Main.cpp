#include <iostream>

#include "Book_Catalogue.h"
#include "Books/Fiction.h"
#include "Books/CookBook.h"
#include "Books/HowTo.h"
#include "Core/Attributes.h"

#include <list>
#include <memory>

void fill(BookCatalogue &catalogue);
void test(const BookCatalogue& catalogue);

int main() 
{
	BookCatalogue catalogue;

	fill(catalogue);
	test(catalogue);

	return 0;
}

void findBooks(const BookCatalogue& catalogue, const std::list<Attributes>& targets) 
{
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

void fill(BookCatalogue& catalogue) 
{
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
}

void test(const BookCatalogue& catalogue)
{
	std::cout << "<------  FIRST TEST CASE  ------>" << std::endl;
	std::list<Attributes> targets1 = {
		{ .m_type = BookType::FICTION, .m_title = "The Great Gatsby" },
		{ .m_type = BookType::FICTION, .m_genre = Genre::DETECTIVE },
		{ .m_type = BookType::FICTION, .m_year = 1960 },
		{ .m_type = BookType::FICTION, .m_genre = Genre::HORROR, .m_year = 1818 },
		{ .m_type = BookType::FICTION, .m_genre = Genre::SCIFI, .m_surname = "King" },
		{ .m_type = BookType::FICTION, .m_genre = Genre::ROMANCE },
		{ .m_type = BookType::FICTION, .m_genre = Genre::HORROR, .m_surname = "King" },
		{ .m_type = BookType::FICTION, .m_title = "1984", .m_name = "George", .m_surname = "Orwell" },
		{ .m_type = BookType::FICTION, .m_title = "life of PI" },
		{ .m_type = BookType::FICTION, .m_title = "Life of PI", .m_name = "Yann", .m_surname = "Martel" },
		{ .m_type = BookType::FICTION },
		{ .m_type = BookType::FICTION, .m_name = "Stephen", .m_surname = "King" },
		{ .m_type = BookType::FICTION, .m_surname = "Shelley" },
		{ .m_type = BookType::FICTION, .m_title = "Ender's Game", .m_surname = "Card" }
	};
	findBooks(catalogue, targets1);

	std::cout << "<------  SECOND TEST CASE  ------>" << std::endl;
	std::list<Attributes> targets2 = {
		{ .m_type = BookType::COOKBOOK, .m_region = Region::CHINA },
		{ .m_type = BookType::ANY, .m_region = Region::CHINA },
		{ .m_type = BookType::ANY, .m_surname = "Lee" },
		{ .m_type = BookType::COOKBOOK, .m_surname = "Lee" },
		{ .m_type = BookType::FICTION, .m_surname = "Lee" },
		{ .m_type = BookType::ANY, .m_genre = Genre::HORROR },
		{ .m_type = BookType::ANY, .m_region = Region::ITALY },
		{ .m_type = BookType::COOKBOOK },
		{ .m_type = BookType::ANY }
	};
	findBooks(catalogue, targets2);

	std::cout << "<------  THIRD TEST CASE  ------>" << std::endl;
	std::list<Attributes> targets3 = {
		{ .m_type = BookType::HOWTO, .m_subject = "programming" },
		{ .m_type = BookType::ANY, .m_subject = "PROGRAMMING" },
		{ .m_type = BookType::ANY, .m_surname = "King" },
		{ .m_type = BookType::HOWTO, .m_surname = "King" },
		{ .m_type = BookType::ANY, .m_name = "Martin" },
		{ .m_type = BookType::ANY, .m_surname = "Martin" },
		{ .m_type = BookType::ANY, .m_genre = Genre::HORROR },
		{ .m_type = BookType::ANY, .m_region = Region::CHINA },
		{ .m_type = BookType::ANY, .m_subject = "cooking" },
		{ .m_type = BookType::HOWTO }
	};
	findBooks(catalogue, targets3);
}
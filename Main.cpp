#include <iostream>

#include "Book_Catalogue.h"

void fill(BookCatalogue &catalogue);
void test(const BookCatalogue& catalogue);

int main() 
{
	BookCatalogue catalogue;

	fill(catalogue);
	test(catalogue);

	return 0;
}

void findBooks(const BookCatalogue& catalogue, std::list<Attributes>& targets) 
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
	catalogue.insertBook(Book(Attributes{
		{ Key::BOOK_TYPE, BookType::FICTION },
		{ Key::GENRE, Genre::CLASSICS },
		{ Key::YEAR, uint16_t(1925) },
		{ Key::TITLE, std::string("The Great Gatsby") },
		{ Key::AUTHOR_NAME, std::string("F. Scott") },
		{ Key::AUTHOR_SURNAME, std::string("Fitzgerald") }
	}));
	catalogue.insertBook(Book({
		{ Key::BOOK_TYPE, BookType::FICTION },
		{ Key::GENRE, Genre::ADVENTURE }, 
		{ Key::YEAR, uint16_t(2001) },
		{ Key::TITLE, std::string("Life of Pi") },
		{ Key::AUTHOR_NAME, std::string("Yann") },
		{ Key::AUTHOR_SURNAME, std::string("Martel") }
	}));
	catalogue.insertBook(Book({
		{ Key::BOOK_TYPE, BookType::FICTION },
		{ Key::GENRE, Genre::ADVENTURE }, 
		{ Key::YEAR, uint16_t(1903) },
		{ Key::TITLE, std::string("The Call of the Wild") },
		{ Key::AUTHOR_NAME, std::string("Jack") },
		{ Key::AUTHOR_SURNAME, std::string("London") }
	}));
	catalogue.insertBook(Book({
		{ Key::BOOK_TYPE, BookType::FICTION },
		{ Key::GENRE, Genre::CLASSICS },
		{ Key::YEAR, uint16_t(1960) },
		{ Key::TITLE, std::string("To Kill a Mockingbird") },
		{ Key::AUTHOR_NAME, std::string("Harper") },
		{ Key::AUTHOR_SURNAME, std::string("Lee") }
	}));
	catalogue.insertBook(Book({
		{ Key::BOOK_TYPE, BookType::FICTION },
		{ Key::GENRE, Genre::CLASSICS },
		{ Key::YEAR, uint16_t(1868) },
		{ Key::TITLE, std::string("Little Women") },
		{ Key::AUTHOR_NAME, std::string("Louisa") },
		{ Key::AUTHOR_SURNAME, std::string("Alcott") }
	}));
	catalogue.insertBook(Book({
		{ Key::BOOK_TYPE, BookType::FICTION },
		{ Key::GENRE, Genre::DETECTIVE }, 
		{ Key::YEAR, uint16_t(1892) },
		{ Key::TITLE, std::string("The Adventures of Sherlock Holmes") },
		{ Key::AUTHOR_NAME, std::string("Conan") },
		{ Key::AUTHOR_SURNAME, std::string("Doyle") }
	}));
	catalogue.insertBook(Book({
		{ Key::BOOK_TYPE, BookType::FICTION },
		{ Key::GENRE, Genre::DETECTIVE }, 
		{ Key::YEAR, uint16_t(1939) },
		{ Key::TITLE, std::string("And Then There Were None") },
		{ Key::AUTHOR_NAME, std::string("Agatha") },
		{ Key::AUTHOR_SURNAME, std::string("Christie") }
	}));
	catalogue.insertBook(Book({
		{ Key::BOOK_TYPE, BookType::FICTION },
		{ Key::GENRE, Genre::HORROR }, 
		{ Key::YEAR, uint16_t(1974) },
		{ Key::TITLE, std::string("Carrie") },
		{ Key::AUTHOR_NAME, std::string("Stephen") },
		{ Key::AUTHOR_SURNAME, std::string("King") }
	}));
	catalogue.insertBook(Book({
		{ Key::BOOK_TYPE, BookType::FICTION },
		{ Key::GENRE, Genre::HORROR }, 
		{ Key::YEAR, uint16_t(1986) },
		{ Key::TITLE, std::string("It: A Novel") },
		{ Key::AUTHOR_NAME, std::string("Stephen") },
		{ Key::AUTHOR_SURNAME, std::string("King") }
	}));
	catalogue.insertBook(Book({
		{ Key::BOOK_TYPE, BookType::FICTION },
		{ Key::GENRE, Genre::HORROR }, 
		{ Key::YEAR, uint16_t(1818) },
		{ Key::TITLE, std::string("Frankenstein") },
		{ Key::AUTHOR_NAME, std::string("Mary") },
		{ Key::AUTHOR_SURNAME, std::string("Shelley") }
	}));
	catalogue.insertBook(Book({
		{ Key::BOOK_TYPE, BookType::FICTION },
		{ Key::GENRE, Genre::SCIFI }, 
		{ Key::YEAR, uint16_t(1968) },
		{ Key::TITLE, std::string("2001: A Space Odyssey") },
		{ Key::AUTHOR_NAME, std::string("Arthur") },
		{ Key::AUTHOR_SURNAME, std::string("Clarke") }
	}));
	catalogue.insertBook(Book({
		{ Key::BOOK_TYPE, BookType::FICTION },
		{ Key::GENRE, Genre::SCIFI }, 
		{ Key::YEAR, uint16_t(1985) },
		{ Key::TITLE, std::string("Ender's Game") },
		{ Key::AUTHOR_NAME, std::string("Orson") },
		{ Key::AUTHOR_SURNAME, std::string("Card") }
	}));

	catalogue.insertBook(Book({ 
		{ Key::BOOK_TYPE, BookType::COOKBOOK },
		{ Key::REGION, Region::CHINA }, 
		{ Key::TITLE, std::string("The Woks of Life") },
		{ Key::AUTHOR_NAME, std::string("Bill") },
		{ Key::AUTHOR_SURNAME, std::string("Leung") }
	}));
	catalogue.insertBook(Book({
		{ Key::BOOK_TYPE, BookType::COOKBOOK },
		{ Key::REGION, Region::CHINA }, 
		{ Key::TITLE, std::string("Chinese Cooking for Dummies") },
		{ Key::AUTHOR_NAME, std::string("Martin") },
		{ Key::AUTHOR_SURNAME, std::string("Yan") }
	}));
	catalogue.insertBook(Book({
		{ Key::BOOK_TYPE, BookType::COOKBOOK },
		{ Key::REGION, Region::FRANCE }, 
		{ Key::TITLE, std::string("Mastering the Art of French Cooking") },
		{ Key::AUTHOR_NAME, std::string("Julia") },
		{ Key::AUTHOR_SURNAME, std::string("Child") }
	}));
	catalogue.insertBook(Book({
		{ Key::BOOK_TYPE, BookType::COOKBOOK },
		{ Key::REGION, Region::INDIA }, 
		{ Key::TITLE, std::string("Made in India") },
		{ Key::AUTHOR_NAME, std::string("Meera") },
		{ Key::AUTHOR_SURNAME, std::string("Sodha") }
	}));
	catalogue.insertBook(Book({
		{ Key::BOOK_TYPE, BookType::COOKBOOK },
		{ Key::REGION, Region::US }, 
		{ Key::TITLE, std::string("The Lee Bros. Southern Cookbook") },
		{ Key::AUTHOR_NAME, std::string("Matt") },
		{ Key::AUTHOR_SURNAME, std::string("Lee") }
	}));

	catalogue.insertBook(Book({ 
		{ Key::BOOK_TYPE, BookType::HOWTO },
		{ Key::SUBJECT, std::string("PROGRAMMING") },
		{ Key::TITLE, std::string("Clean Code") },
		{ Key::AUTHOR_NAME, std::string("Robert") },
		{ Key::AUTHOR_SURNAME, std::string("Martin") }
	}));
	catalogue.insertBook(Book({
		{ Key::BOOK_TYPE, BookType::HOWTO },
		{ Key::SUBJECT, std::string("PROGRAMMING") },
		{ Key::TITLE, std::string("The Pragmatic Programmer") },
		{ Key::AUTHOR_NAME, std::string("Andrew") },
		{ Key::AUTHOR_SURNAME, std::string("Hunt") }
	}));
	catalogue.insertBook(Book({
		{ Key::BOOK_TYPE, BookType::HOWTO },
		{ Key::SUBJECT, std::string("GARDENING") }, 
		{ Key::TITLE, std::string("The Vegetable Gardener's Bible") },
		{ Key::AUTHOR_NAME, std::string("Edward") },
		{ Key::AUTHOR_SURNAME, std::string("Smith") }
	}));
	catalogue.insertBook(Book({
		{ Key::BOOK_TYPE, BookType::HOWTO },
		{ Key::SUBJECT, std::string("COMMUNICATION") },
		{ Key::TITLE, std::string("How to Win Friends and Influence People") },
		{ Key::AUTHOR_NAME, std::string("Dale") },
		{ Key::AUTHOR_SURNAME, std::string("Carnegie") }
	}));
	catalogue.insertBook(Book({
		{ Key::BOOK_TYPE, BookType::HOWTO },
		{ Key::SUBJECT, std::string("WRITING") },
		{ Key::TITLE, std::string("On Writing") },
		{ Key::AUTHOR_NAME, std::string("Stephen") },
		{ Key::AUTHOR_SURNAME, std::string("King") }
	}));
}

void test(const BookCatalogue& catalogue)
{
	std::cout << "<------  FIRST TEST CASE  ------>" << std::endl;
	std::list<Attributes> targets1 = {
		{
			{ Key::BOOK_TYPE, BookType::FICTION },
			{ Key::TITLE, std::string("The Great Gatsby") }
		},
		{
			{ Key::BOOK_TYPE, BookType::FICTION },
			{ Key::GENRE, Genre::DETECTIVE }
		},
		{
			{ Key::BOOK_TYPE, BookType::FICTION },
			{ Key::YEAR, uint16_t(1960) }
		},
		{
			{ Key::BOOK_TYPE, BookType::FICTION },
			{ Key::GENRE, Genre::HORROR },
			{ Key::YEAR, uint16_t(1818) }
		},
		{
			{ Key::BOOK_TYPE, BookType::FICTION },
			{ Key::GENRE, Genre::SCIFI },
			{ Key::AUTHOR_SURNAME, std::string("King") }
		},
		{
			{ Key::BOOK_TYPE, BookType::FICTION },
			{ Key::GENRE, Genre::ROMANCE }
		},
		{
			{ Key::BOOK_TYPE, BookType::FICTION },
			{ Key::GENRE, Genre::HORROR },
			{ Key::AUTHOR_SURNAME, std::string("King") }
		},
		{
			{ Key::BOOK_TYPE, BookType::FICTION },
			{ Key::TITLE, std::string("1984") },
			{ Key::AUTHOR_NAME, std::string("George") },
			{ Key::AUTHOR_SURNAME, std::string("Orwell") }
		},
		{
			{ Key::BOOK_TYPE, BookType::FICTION },
			{ Key::TITLE, std::string("life of PI") }
		},
		{
			{ Key::BOOK_TYPE, BookType::FICTION },
			{ Key::TITLE, std::string("Life of PI") },
			{ Key::AUTHOR_NAME, std::string("Yann") },
			{ Key::AUTHOR_SURNAME, std::string("Martel") }
		},
		{
			{ Key::BOOK_TYPE, BookType::FICTION } 
		},
		{
			{ Key::BOOK_TYPE, BookType::FICTION },
			{ Key::AUTHOR_NAME, std::string("Stephen") },
			{ Key::AUTHOR_SURNAME, std::string("King") }
		},
		{
			{ Key::BOOK_TYPE, BookType::FICTION },
			{ Key::AUTHOR_SURNAME, std::string("Shelley") }
		},
		{
			{ Key::BOOK_TYPE, BookType::FICTION },
			{ Key::TITLE, std::string("Ender's Game") },
			{ Key::AUTHOR_SURNAME, std::string("Card") }
		}
	};
	findBooks(catalogue, targets1);

	std::cout << "<------  SECOND TEST CASE  ------>" << std::endl;
	std::list<Attributes> targets2 = 
	{
		{ 
			{ Key::BOOK_TYPE, BookType::COOKBOOK },
			{ Key::REGION, Region::CHINA }
		},
		{ 
			{ Key::REGION, Region::CHINA }
		},
		{
			{ Key::AUTHOR_SURNAME, std::string("Lee") } 
		},
		{
			{ Key::BOOK_TYPE, BookType::COOKBOOK }, 
			{ Key::AUTHOR_SURNAME, std::string("Lee") }
		},
		{ 
			{ Key::BOOK_TYPE, BookType::FICTION }, 
			{ Key::AUTHOR_SURNAME, std::string("Lee") } 
		},
		{ 
			{ Key::GENRE, Genre::HORROR } 
		},
		{ 
			{ Key::REGION, Region::ITALY } 
		},
		{ 
			{ Key::BOOK_TYPE, BookType::COOKBOOK }
		},
		{
			// ANY
		}
	};
	findBooks(catalogue, targets2);

	std::cout << "<------  THIRD TEST CASE  ------>" << std::endl;
	std::list<Attributes> targets3 = {
		{ 
			{ Key::BOOK_TYPE, BookType::HOWTO },
			{ Key::SUBJECT, std::string("programming") }
		},
		{ 
			{ Key::SUBJECT, std::string("PROGRAMMING") }
		},
		{ 
			{ Key::AUTHOR_SURNAME, std::string("King") }
		},
		{ 
			{ Key::BOOK_TYPE, BookType::HOWTO },
			{ Key::AUTHOR_SURNAME, std::string("King") }
		},
		{ 
			{ Key::AUTHOR_NAME, std::string("Martin") }
		},
		{ 
			{ Key::AUTHOR_SURNAME, std::string("Martin") }
		},
		{ 
			{ Key::GENRE, Genre::HORROR }
		},
		{ 
			{ Key::REGION, Region::CHINA }
		},
		{ 
			{ Key::SUBJECT, std::string("cooking") }
		},
		{ 
			{ Key::BOOK_TYPE, BookType::HOWTO }
		}
	};
	findBooks(catalogue, targets3);
}
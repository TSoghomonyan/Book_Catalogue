#include "Book.h"

book_type Book::type() const { return m_type; }

const Attributes& Book::attributes() const { return m_attributes; }

bool Book::checkStrings(const std::string& str1, const std::string& str2) const
{
	if (str1.size() != str2.size()) {
		return false;
	}

	for (size_t i = 0; i < str1.size(); ++i) {
		if (tolower(str1[i]) != tolower(str2[i])) {
			return false;
		}
	}

	return true;
}

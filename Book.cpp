#include "Book.h"

bool Book::matches(const SearchTarget& target) const
{
	if (target.type != book_type::ANY && target.type != m_type) {
		return false;
	}

	const Attributes& targetAttributes = target.attributes;
	if (!targetAttributes.m_title.empty() && 
		!checkStrings(m_attributes.m_title, targetAttributes.m_title)) { return false; }
	if (!targetAttributes.m_name.empty() &&
		!checkStrings(m_attributes.m_name, targetAttributes.m_name)) { return false; }
	if (!targetAttributes.m_surname.empty() &&
		!checkStrings(m_attributes.m_surname, targetAttributes.m_surname)) { return false; }

	return matchesOwn(target);
}

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

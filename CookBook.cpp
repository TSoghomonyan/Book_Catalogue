#include "CookBook.h"

Region CookBook::region() const
{
	return m_attributes.m_region;
}

const std::string& CookBook::title() const
{
	return m_attributes.m_title;
}

const std::string& CookBook::name() const
{
	return m_attributes.m_name;
}

const std::string& CookBook::surname() const
{
	return m_attributes.m_surname;
}

bool CookBook::matchesOwn(const SearchTarget& target) const
{
	const Attributes& targetAttributes = target.attributes;

	if (targetAttributes.m_genre != Genre::NONE &&
		targetAttributes.m_year != 0) {
		return false;
	}

	return targetAttributes.m_region == Region::NONE || 
		targetAttributes.m_region == m_attributes.m_region;
}

std::ostream& CookBook::print(std::ostream& os) const
{
	os << "{KIND: COOKBOOK, "
		<< "TITLE: '" << m_attributes.m_title << "', "
		<< "SURNAME: '" << m_attributes.m_surname << "', "
		<< "NAME: '" << m_attributes.m_name << "', "
		<< "REGION: '" << m_attributes.m_region << "'}";
	return os;
}

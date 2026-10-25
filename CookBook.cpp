#include "CookBook.h"

Region CookBook::region() const
{
	return m_attributes.m_region;
}

const uint16_t CookBook::year() const
{
	return m_attributes.m_year;
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

bool CookBook::matches(const Book* target) const
{
	if (m_type != target->type()) {
		return false;
	}

	const Attributes& targetAttributes = target->attributes();

	const Region targetRegion = targetAttributes.m_region;
	const uint16_t targetYear = targetAttributes.m_year;
	const std::string& targetTitle = targetAttributes.m_title;
	const std::string& targetName = targetAttributes.m_name;
	const std::string& targetSurname = targetAttributes.m_surname;

	bool check = true;
	check &= Region::NONE == targetRegion || m_attributes.m_region == targetRegion;
	check &= 0 == targetYear || m_attributes.m_year == targetYear;
	check &= targetTitle.empty() || checkStrings(m_attributes.m_title, targetTitle);
	check &= targetName.empty() || checkStrings(m_attributes.m_name, targetName);
	check &= targetSurname.empty() || checkStrings(m_attributes.m_surname, targetSurname);
	return check;
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

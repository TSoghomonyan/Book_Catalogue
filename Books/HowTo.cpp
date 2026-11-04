#include "HowTo.h"

const std::string& HowTo::subject() const
{
	return m_attributes.m_subject;
}

bool HowTo::matchesOwn(const SearchTarget& target) const
{
	const Attributes& targetAttributes = target.attributes;

	if (targetAttributes.m_genre != Genre::NONE ||
		targetAttributes.m_region != Region::NONE ||
		targetAttributes.m_year != 0) {
		return false;
	}

	return targetAttributes.m_subject.empty() ||
		checkStrings(m_attributes.m_subject, targetAttributes.m_subject);
}

std::ostream& HowTo::print(std::ostream& os) const
{
	os << "{KIND: '" << m_type << "', "
		<< "TITLE: '" << m_attributes.m_title << "', "
		<< "SURNAME: '" << m_attributes.m_surname << "', "
		<< "NAME: '" << m_attributes.m_name << "', "
		<< "SUBJECT: '" << m_attributes.m_subject << "'}";
	return os;
}
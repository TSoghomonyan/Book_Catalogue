#include "Fiction.h"

Genre Fiction::genre() const 
{ 
	return m_attributes.m_genre; 
}

const uint16_t Fiction::year() const 
{ 
	return m_attributes.m_year; 
}

bool Fiction::matchesOwn(const SearchTarget& target) const
{
	const Attributes& targetAttributes = target.attributes;
	if (targetAttributes.m_region != Region::NONE ||
		!targetAttributes.m_subject.empty()) {
		return false;
	}

	return (targetAttributes.m_genre == Genre::NONE ||
			targetAttributes.m_genre == m_attributes.m_genre) &&
		   (targetAttributes.m_year == 0 || 
			targetAttributes.m_year == m_attributes.m_year);
}

std::ostream& Fiction::print(std::ostream& os) const
{
	os << "{KIND: '" << m_type << "', "
		<< "TITLE: '" << m_attributes.m_title << "', "
		<< "SURNAME: '" << m_attributes.m_surname << "', "
		<< "NAME: '" << m_attributes.m_name << "', "
		<< "YEAR: '" << m_attributes.m_year << "', "
		<< "GENRE: '" << m_attributes.m_genre << "'}";
	return os;
}

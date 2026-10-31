#include "Fiction.h"

Genre Fiction::genre() const 
{ 
	return m_attributes.m_genre; 
}

const uint16_t Fiction::year() const 
{ 
	return m_attributes.m_year; 
}

const std::string& Fiction::title() const 
{ 
	return m_attributes.m_title; 
}

const std::string& Fiction::name() const 
{ 
	return m_attributes.m_name; 
}

const std::string& Fiction::surname() const 
{ 
	return m_attributes.m_surname; 
}

bool Fiction::matchesOwn(const SearchTarget& target) const
{
	const Attributes& targetAttributes = target.attributes;
	if (targetAttributes.m_region != Region::NONE) {
		return false;
	}

	return (targetAttributes.m_genre == Genre::NONE ||
			targetAttributes.m_genre == m_attributes.m_genre) &&
		   (targetAttributes.m_year == 0 || 
			targetAttributes.m_year == m_attributes.m_year);
}

std::ostream& Fiction::print(std::ostream& os) const
{
	os << "{KIND: FICTION, "
		<< "TITLE: '" << m_attributes.m_title << "', "
		<< "SURNAME: '" << m_attributes.m_surname << "', "
		<< "NAME: '" << m_attributes.m_name << "', "
		<< "YEAR: '" << m_attributes.m_year << "', "
		<< "GENRE: '" << m_attributes.m_genre << "'}";
	return os;
}

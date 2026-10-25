#include "Fiction.h"

Genre Fiction::genre() const { return m_attributes.m_genre; }

const uint16_t Fiction::year() const { return m_attributes.m_year; }

const std::string& Fiction::title() const { return m_attributes.m_title; }

const std::string& Fiction::name() const { return m_attributes.m_name; }

const std::string& Fiction::surname() const { return m_attributes.m_surname; }

bool Fiction::matches(const Book* target) const
{
	if (m_type != target->type()) {
		return false;
	}

	const Attributes& targetAttributes = target->attributes();

	const Genre targetGenre = targetAttributes.m_genre;
	const uint16_t targetYear = targetAttributes.m_year;
	const std::string& targetTitle = targetAttributes.m_title;
	const std::string& targetName = targetAttributes.m_name;
	const std::string& targetSurname = targetAttributes.m_surname;

	bool check = true;
	check &= Genre::NONE == targetGenre || m_attributes.m_genre == targetGenre;
	check &= 0 == targetYear || m_attributes.m_year == targetYear;
	check &= targetTitle.empty() || checkStrings(m_attributes.m_title, targetTitle);
	check &= targetName.empty() || checkStrings(m_attributes.m_name, targetName);
	check &= targetSurname.empty() || checkStrings(m_attributes.m_surname, targetSurname);
	return check;
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

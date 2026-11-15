#include "Book.h"

bool Book::matches(const Attributes& target) const
{
	return m_attributes.isMatch(target);
}

BookType Book::type() const 
{ 
	return m_attributes.m_type; 
}

const std::string& Book::title() const
{
	return m_attributes.m_title;
}

const std::string& Book::name() const
{
	return m_attributes.m_name;
}

const std::string& Book::surname() const
{
	return m_attributes.m_surname;
}

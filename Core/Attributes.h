#pragma once

#include "BookType.h"
#include "Genre.h"
#include "Region.h"
#include "Key.h"

#include <assert.h>
#include <cstdint>
#include <variant>
#include <string>
#include <map>

using Value = std::variant<uint16_t, std::string,
							BookType, Genre, Region>;

enum type_index : uint8_t
{
	UINT16_INDEX = 0,
	STRING_INDEX,
	BOOK_TYPE_INDEX,
	GENRE_INDEX,
	REGION_INDEX
};

class Attributes
{
public:
	inline Attributes(std::initializer_list<std::pair<const Key, Value>> pairs)
		: m_pairs(pairs)
	{
		for (auto cit = m_pairs.cbegin(); cit != m_pairs.cend(); ++cit) {
			const Key key = cit->first;
			const size_t index = cit->second.index();

			switch (key) {
			case Key::YEAR:
				assert(UINT16_INDEX == index); break;
			case Key::TITLE:
			case Key::AUTHOR_NAME:
			case Key::AUTHOR_SURNAME:
			case Key::SUBJECT:
				assert(STRING_INDEX == index); break;
			case Key::BOOK_TYPE:
				assert(BOOK_TYPE_INDEX == index); break;
			case Key::GENRE:
				assert(GENRE_INDEX == index); break;
			case Key::REGION:
				assert(REGION_INDEX == index); break;
			}
		}
	}

	inline bool isMatching(const Attributes& target) const
	{
		const auto& targetPairs = target.m_pairs;
		for (auto cit = targetPairs.cbegin(); cit != targetPairs.cend(); ++cit) {
			const Key targetKey = cit->first;
			const Value targetValue = cit->second;
			if (!isMatchingPair(targetKey, targetValue)) {
				return false;
			}
		}
		return true;
	}

	inline
	friend std::ostream& operator<<(std::ostream& os, const Attributes& attributes)
	{
		const auto& attributesPairs = attributes.m_pairs;

		os << "{";

		for (auto cit = attributesPairs.cbegin(); cit != attributesPairs.cend(); ++cit) {
			Key key = cit->first;
			Value value = cit->second;

			if (cit != attributesPairs.begin()) os << ", ";
			os << key << ": ";

			switch (key)
			{
			case Key::BOOK_TYPE:
				os << get<BookType>(value); break;
			case Key::AUTHOR_NAME:
			case Key::AUTHOR_SURNAME:
			case Key::TITLE:
			case Key::SUBJECT:
				os << "'" << get<std::string>(value) << "'"; break;
			case Key::GENRE:
				os << get<Genre>(value); break;
			case Key::REGION:
				os << get<Region>(value); break;
			case Key::YEAR:
				os << get<uint16_t>(value); break;
			}
		}

		os << "}";
		return os;
	}

private:
	inline bool isMatchingPair(const Key targetKey, const Value& targetValue) const
	{
		const auto find = m_pairs.find(targetKey);
		if (find == m_pairs.end()) return false;

		if (STRING_INDEX == find->second.index()) {
			return checkStrings(get<std::string>(targetValue),
								get<std::string>(find->second));
		} else {
			return targetValue == find->second;
		}
	}

	// case insensitive
	inline bool checkStrings(const std::string& str1, const std::string& str2) const 
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

private:
	std::map<Key, Value> m_pairs;
};

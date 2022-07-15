#include "WordHistogramSuite.h"
#include "statistics.h"
#include "cute.h"

#include <algorithm>
#include <map>
#include <istream>
#include <iterator>
#include <sstream>
#include <string>

namespace text {

inline namespace {

std::ostream& operator<<(std::ostream &out, std::map<Word, int> const &occurrences) {
	out << "{\n";
	std::transform(std::cbegin(occurrences), std::cend(occurrences), std::ostream_iterator<std::string> { out, "\n" }, [](auto const &occurrence) {
		std::ostringstream result { };
		result << "\t{\"" << occurrence.first << "\": " << occurrence.second << "},";
		return result.str();
	});
	out << "}\n";
	return out;
}

}

}

using text::Word;

void testHistogramEmptyInput() {
	std::istringstream input { };
	auto const result = statistics::histogram(input);
	ASSERTM("Result is expected to be empty for empty input.", result.empty());
}

void testHistogramWithSingleWord() {
	std::map<Word, int> expected { { Word { "Wuuzaa" }, 1 } };
	std::istringstream input { "Wuuzaa" };
	auto const result = statistics::histogram(input);
	ASSERT_EQUAL(expected, result);
}

void testHistogramWithSameWordInDifferentCasings() {
	std::map<Word, int> expected { { Word { "Wuuzaa" }, 4 } };
	std::istringstream input { "Wuuzaa wuuzaa wUUzAA WUUZAA" };
	auto const result = statistics::histogram(input);
	ASSERT_EQUAL(expected, result);
}

void testHistogramOfMutlipleWords() {
	std::map<Word, int> expected {
		{Word{"all"}, 2},
		{Word{"and"}, 1},
		{Word{"bind"}, 1},
		{Word{"bring"}, 1},
		{Word{"Dark"}, 2},
		{Word{"darkness"}, 1},
		{Word{"die"}, 1},
		{Word{"doomed"}, 1},
		{Word{"Dwarf"}, 1},
		{Word{"Elven"}, 1},
		{Word{"find"}, 1},
		{Word{"for"}, 4},
		{Word{"halls"}, 1},
		{Word{"his"}, 1},
		{Word{"in"}, 4},
		{Word{"kings"}, 1},
		{Word{"Land"}, 2},
		{Word{"lie"}, 2},
		{Word{"Lord"}, 1},
		{Word{"lords"}, 1},
		{Word{"Men"}, 1},
		{Word{"Mordor"}, 2},
		{Word{"Mortal"}, 1},
		{Word{"Nine"}, 1},
		{Word{"of"}, 3},
		{Word{"on"}, 1},
		{Word{"One"}, 4},
		{Word{"Ring"}, 3},
		{Word{"Rings"}, 1},
		{Word{"rule"}, 1},
		{Word{"Seven"}, 1},
		{Word{"Shadows"}, 2},
		{Word{"sky"}, 1},
		{Word{"stone"}, 1},
		{Word{"the"}, 9},
		{Word{"their"}, 1},
		{Word{"them"}, 4},
		{Word{"Three"}, 1},
		{Word{"throne"}, 1},
		{Word{"to"}, 4},
		{Word{"under"}, 1},
		{Word{"where"}, 2}
	};
	//Test-Input from: https://lotr.fandom.com/de/wiki/Ringgedicht
	std::istringstream input {
		"Three Rings for the Elven-kings under the sky,\n"
		"Seven for the Dwarf-lords in their halls of stone,,\n"
		"Nine for Mortal Men doomed to die,,\n"
		"One for the Dark Lord on his dark throne,\n"
		"In the Land of Mordor where the Shadows lie.,\n"
		"One Ring to rule them all, One Ring to find them,,\n"
		"One Ring to bring them all and in the darkness bind them,\n"
		"In the Land of Mordor where the Shadows lie." };
	auto const result = statistics::histogram(input);
	ASSERT_EQUAL(expected, result);
}

void testHistogramWithFlySentence() {
	std::map<Word, int> expected { { Word { "Fliegen" }, 6 }, {Word{"hinter"}, 1}, {Word{"nach"}, 1}, {Word{"Wenn"}, 1} };
	std::istringstream input { "Wenn hinter Fliegen Fliegen fliegen, fliegen Fliegen Fliegen nach." };
	auto const result = statistics::histogram(input);
	ASSERT_EQUAL(expected, result);
}


cute::suite make_suite_WordHistogramSuite() {
	cute::suite s { };
	s.push_back(CUTE(testHistogramEmptyInput));
	s.push_back(CUTE(testHistogramWithSingleWord));
	s.push_back(CUTE(testHistogramWithSameWordInDifferentCasings));
	s.push_back(CUTE(testHistogramOfMutlipleWords));
	s.push_back(CUTE(testHistogramWithFlySentence));
	return s;
}

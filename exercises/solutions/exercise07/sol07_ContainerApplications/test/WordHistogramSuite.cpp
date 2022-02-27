#include "WordHistogramSuite.h"
#include "statistics.h"
#include "cute.h"

#include <algorithm>
#include <map>
#include <istream>
#include <iterator>
#include <sstream>
#include <string>

namespace word {

inline namespace {

std::ostream& operator<<(std::ostream &out, std::map<word::Word, int> const &occurrences) {
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


void testHistogramEmptyInput() {
	std::istringstream input { };
	auto const result = statistics::histogram(input);
	ASSERTM("Result is expected to be empty for empty input.", result.empty());
}

void testHistogramWithSingleWord() {
	std::map<word::Word, int> expected { { word::Word { "Wuuzaa" }, 1 } };
	std::istringstream input { "Wuuzaa" };
	auto const result = statistics::histogram(input);
	ASSERT_EQUAL(expected, result);
}

void testHistogramWithSameWordInDifferentCasings() {
	std::map<word::Word, int> expected { { word::Word { "Wuuzaa" }, 4 } };
	std::istringstream input { "Wuuzaa wuuzaa wUUzAA WUUZAA" };
	auto const result = statistics::histogram(input);
	ASSERT_EQUAL(expected, result);
}

void testHistogramOfMutlipleWords() {
	std::map<word::Word, int> expected {
		{word::Word{"all"}, 2},
		{word::Word{"and"}, 1},
		{word::Word{"bind"}, 1},
		{word::Word{"bring"}, 1},
		{word::Word{"Dark"}, 2},
		{word::Word{"darkness"}, 1},
		{word::Word{"die"}, 1},
		{word::Word{"doomed"}, 1},
		{word::Word{"Dwarf"}, 1},
		{word::Word{"Elven"}, 1},
		{word::Word{"find"}, 1},
		{word::Word{"for"}, 4},
		{word::Word{"halls"}, 1},
		{word::Word{"his"}, 1},
		{word::Word{"in"}, 4},
		{word::Word{"kings"}, 1},
		{word::Word{"Land"}, 2},
		{word::Word{"lie"}, 2},
		{word::Word{"Lord"}, 1},
		{word::Word{"lords"}, 1},
		{word::Word{"Men"}, 1},
		{word::Word{"Mordor"}, 2},
		{word::Word{"Mortal"}, 1},
		{word::Word{"Nine"}, 1},
		{word::Word{"of"}, 3},
		{word::Word{"on"}, 1},
		{word::Word{"One"}, 4},
		{word::Word{"Ring"}, 3},
		{word::Word{"Rings"}, 1},
		{word::Word{"rule"}, 1},
		{word::Word{"Seven"}, 1},
		{word::Word{"Shadows"}, 2},
		{word::Word{"sky"}, 1},
		{word::Word{"stone"}, 1},
		{word::Word{"the"}, 9},
		{word::Word{"their"}, 1},
		{word::Word{"them"}, 4},
		{word::Word{"Three"}, 1},
		{word::Word{"throne"}, 1},
		{word::Word{"to"}, 4},
		{word::Word{"under"}, 1},
		{word::Word{"where"}, 2}
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
	std::map<word::Word, int> expected { { word::Word { "Fliegen" }, 6 }, {word::Word{"hinter"}, 1}, {word::Word{"nach"}, 1}, {word::Word{"Wenn"}, 1} };
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

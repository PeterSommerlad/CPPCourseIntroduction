#include "TopSuite.h"

#include "cute.h"
#include "statistics.h"

#include <map>
#include <set>
#include <string>

using namespace statistics;
using word::Word;
using Histogram = std::map<word::Word, int>;

Word operator"" _w(char const * literal, size_t length) {
	return Word{std::string{literal}};
}

void testTopForEmptyMapAndZeroNIsEmpty() {
	auto const result = statistics::top(Histogram{}, 0);
	ASSERTM("Result is expected to be empty for empty map.", result.empty());
}

void testTopForEmptyMapAndLargeNIsEmpty() {
	auto const result = statistics::top(Histogram{}, 10);
	ASSERTM("Result is expected to be empty for empty map.", result.empty());
}

void testTopForNonEmptyMapAndZeroNIsEmpty() {
	auto const result = statistics::top(Histogram{{"word"_w, 1}, {"number"_w, 2}}, 0);
	ASSERTM("Result is expected to be empty for empty map.", result.empty());
}

void testTopForNonEmptyMapAndLargerN() {
	std::set<statistics::HistogramEntry> const expected{
		{"a"_w, 4},
		{"b"_w, 5},
		{"c"_w, 3}
	};
	Histogram const histogram{
		{"a"_w, 4},
		{"b"_w, 5},
		{"c"_w, 3}
	};
	auto const result = statistics::top(histogram, 5);
	ASSERT_EQUAL(expected, result);
}

void testTopForNonEmptyMapAndSmallerN() {
	std::set<statistics::HistogramEntry> const expected{
		{"the"_w, 9},
		{"for"_w, 4},
		{"in"_w, 4},
		{"One"_w, 4},
		{"them"_w, 4}
	};
	Histogram const histogram {
		{"all"_w, 2},
		{"and"_w, 1},
		{"bind"_w, 1},
		{"bring"_w, 1},
		{"Dark"_w, 2},
		{"darkness"_w, 1},
		{"die"_w, 1},
		{"doomed"_w, 1},
		{"Dwarf"_w, 1},
		{"Elven"_w, 1},
		{"find"_w, 1},
		{"for"_w, 4},
		{"halls"_w, 1},
		{"his"_w, 1},
		{"in"_w, 4},
		{"kings"_w, 1},
		{"Land"_w, 2},
		{"lie"_w, 2},
		{"Lord"_w, 1},
		{"lords"_w, 1},
		{"Men"_w, 1},
		{"Mordor"_w, 2},
		{"Mortal"_w, 1},
		{"Nine"_w, 1},
		{"of"_w, 3},
		{"on"_w, 1},
		{"One"_w, 4},
		{"Ring"_w, 3},
		{"Rings"_w, 1},
		{"rule"_w, 1},
		{"Seven"_w, 1},
		{"Shadows"_w, 2},
		{"sky"_w, 1},
		{"stone"_w, 1},
		{"the"_w, 9},
		{"their"_w, 1},
		{"them"_w, 4},
		{"Three"_w, 1},
		{"throne"_w, 1},
		{"to"_w, 4},
		{"under"_w, 1},
		{"where"_w, 2}
	};
	auto const result = statistics::top(histogram, 5);
	ASSERT_EQUAL(expected, result);
}

cute::suite make_suite_TopSuite() {
	cute::suite s{};
	s.push_back(CUTE(testTopForEmptyMapAndZeroNIsEmpty));
	s.push_back(CUTE(testTopForEmptyMapAndLargeNIsEmpty));
	s.push_back(CUTE(testTopForNonEmptyMapAndZeroNIsEmpty));
	s.push_back(CUTE(testTopForNonEmptyMapAndLargerN));
	s.push_back(CUTE(testTopForNonEmptyMapAndSmallerN));
	return s;
}

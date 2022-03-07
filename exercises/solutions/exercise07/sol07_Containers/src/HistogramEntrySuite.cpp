#include "HistogramEntrySuite.h"
#include "cute.h"
#include "statistics.h"

#include <iterator>

#include <set>
#include <sstream>
#include <vector>

using statistics::HistogramEntry;
using text::Word;

void testSameHistogramEntryIsEqual() {
	HistogramEntry entry{Word{"Mouse"}, 15};
	ASSERT_EQUAL(entry, entry);
}

void testEqualHistogramEntriesAreEqual() {
	HistogramEntry entry1{Word{"Train"}, 15};
	HistogramEntry entry2{Word{"Train"}, 15};
	ASSERT_EQUAL(entry1, entry2);
}

void testDifferentWordIsNotEqual() {
	HistogramEntry entry1{Word{"Screen"}, 1};
	HistogramEntry entry2{Word{"Sun"}, 1};
	ASSERT_NOT_EQUAL_TO(entry1, entry2);
}

void testDifferentOccurrenceIsNnotEqual() {
	HistogramEntry entry1{Word{"Grass"}, 4};
	HistogramEntry entry2{Word{"Grass"}, 3};
	ASSERT_NOT_EQUAL_TO(entry1, entry2);
}

void testSortingOfHistogramEntries() {
	std::vector<HistogramEntry> expected{
		{Word{"Year"}, 15},
		{Word{"Day"}, 4},
		{Word{"Month"}, 4},
		{Word{"Century"}, 1},
		{Word{"Epoch"}, 0},
	};
	std::set<HistogramEntry> entries{cbegin(expected), cend(expected)};
	
	ASSERT_EQUAL_RANGES(cbegin(expected), cend(expected), cbegin(entries), cend(entries));
}

void testLessThanByOccurrence() {
	HistogramEntry entry1{Word{"Bottle"}, 9};
	HistogramEntry entry2{Word{"Bottle"}, 8};
	ASSERT_LESS(entry1, entry2);
}

void testLessThanByWord() {
	HistogramEntry entry1{Word{"Car"}, 7};
	HistogramEntry entry2{Word{"Truck"}, 7};
	ASSERT_LESS(entry1, entry2);
}

void testLessThanOrEqual() {
	HistogramEntry entry1{Word{"Tape"}, 9};
	HistogramEntry entry2{Word{"CD"}, 5};
	ASSERT_LESS_EQUAL(entry1, entry2);
}

void testGreaterThan() {
	HistogramEntry entry1{Word{"Knife"}, 7};
	HistogramEntry entry2{Word{"Fork"}, 7};
	ASSERT_GREATER(entry1, entry2);
}

void testGreaterEqual() {
	HistogramEntry entry1{Word{"Table"}, 0};
	HistogramEntry entry2{Word{"Chair"}, 100};
	ASSERT_GREATER_EQUAL(entry1, entry2);
}

void testOutputOperator() {
	std::ostringstream out{};
	HistogramEntry const entry { Word { "Lamp" }, 42 };
	out << entry;
	ASSERT_EQUAL("Lamp: 42", out.str());
}

cute::suite make_suite_HistogramEntrySuite() {
	cute::suite s { };
	s.push_back(CUTE(testSameHistogramEntryIsEqual));
	s.push_back(CUTE(testEqualHistogramEntriesAreEqual));
	s.push_back(CUTE(testDifferentWordIsNotEqual));
	s.push_back(CUTE(testDifferentOccurrenceIsNnotEqual));
	s.push_back(CUTE(testSortingOfHistogramEntries));
	s.push_back(CUTE(testLessThanByOccurrence));
	s.push_back(CUTE(testLessThanByWord));
	s.push_back(CUTE(testLessThanOrEqual));
	s.push_back(CUTE(testGreaterThan));
	s.push_back(CUTE(testGreaterEqual));
	s.push_back(CUTE(testOutputOperator));
	return s;
}

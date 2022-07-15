#include "PrintOccurrencesSuite.h"
#include "statistics.h"
#include "cute.h"

#include <sstream>
#include <string>


using statistics::printOccurrences;

void testOneRingToRuleThemAllOccurrences() {
	std::istringstream input {
		"Three Rings for the Elven-kings under the sky,\n"
		"Seven for the Dwarf-lords in their halls of stone,,\n"
		"Nine for Mortal Men doomed to die,,\n"
		"One for the Dark Lord on his dark throne,\n"
		"In the Land of Mordor where the Shadows lie.,\n"
		"One Ring to rule them all, One Ring to find them,,\n"
		"One Ring to bring them all and in the darkness bind them,\n"
		"In the Land of Mordor where the Shadows lie." };
	std::ostringstream output {};
	std::string expected {
		"the: 9\n"
		"for: 4\n"
		"in: 4\n"
	};
	printOccurrences(input, output, 3);
	ASSERT_EQUAL(expected, output.str());
}

void testFlies() {
	std::istringstream input {
			"Wenn hinter Fliegen Fliegen fliegen, fliegen Fliegen Fliegen nach." };
		std::ostringstream output {};
		std::string expected {
			"Fliegen: 6\n"
			"hinter: 1\n"
			"nach: 1\n"
			"Wenn: 1\n"
		};
		printOccurrences(input, output, 6);
		ASSERT_EQUAL(expected, output.str());
}

cute::suite make_suite_PrintOccurrencesSuite() {
	cute::suite s { };
	s.push_back(CUTE(testOneRingToRuleThemAllOccurrences));
	s.push_back(CUTE(testFlies));
	return s;
}

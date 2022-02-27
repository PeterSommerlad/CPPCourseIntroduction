#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

#include "allcharc.h"
#include <sstream>

void testAllcharcOnEmptyIstream() {
	std::istringstream input{};
	ASSERT_EQUAL(0u, allcharc(input));
}

void testAllcharcOnSingleLineIstream() {
	std::istringstream input{"single line"};
	ASSERT_EQUAL(11u, allcharc(input));
}

void testAllcharcOnMultiLineIstream() {
	std::istringstream input{"multi \n line\n  \n stream"};
	ASSERT_EQUAL(23u, allcharc(input));
}

void testAllcharcOnWhitespaceOnlyIstream() {
	std::istringstream input{"   \n\n\t\t   "};
	ASSERT_EQUAL(10u, allcharc(input));
}

bool runAllTests(int argc, char const *argv[]) {
	cute::suite s{};
	s.push_back(CUTE(testAllcharcOnEmptyIstream));
	s.push_back(CUTE(testAllcharcOnSingleLineIstream));
	s.push_back(CUTE(testAllcharcOnMultiLineIstream));
	s.push_back(CUTE(testAllcharcOnWhitespaceOnlyIstream));
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner = cute::makeRunner(lis, argc, argv);
	bool success = runner(s, "AllTests");
	return success;
}

int main(int argc, char const *argv[]) {
    return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}

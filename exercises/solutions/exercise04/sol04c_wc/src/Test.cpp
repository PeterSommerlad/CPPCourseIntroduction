#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

#include "wc.h"
#include <sstream>

void testWcOnEmptyIstream() {
	std::istringstream input{};
	ASSERT_EQUAL(0u, wc(input));
}

void testWcOnSingleLineIstream() {
	std::istringstream input{"single line"};
	ASSERT_EQUAL(2u, wc(input));
}

void testWcOnMultiLineIstream() {
	std::istringstream input{"multi \n line\n  \n stream"};
	ASSERT_EQUAL(3u, wc(input));
}

void testWcOnWhitespaceOnlyIstream() {
	std::istringstream input{"   \n\n\t\t   "};
	ASSERT_EQUAL(0u, wc(input));
}

bool runAllTests(int argc, char const *argv[]) {
	cute::suite s{};
	s.push_back(CUTE(testWcOnEmptyIstream));
	s.push_back(CUTE(testWcOnSingleLineIstream));
	s.push_back(CUTE(testWcOnMultiLineIstream));
	s.push_back(CUTE(testWcOnWhitespaceOnlyIstream));
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner = cute::makeRunner(lis, argc, argv);
	bool success = runner(s, "AllTests");
	return success;
}

int main(int argc, char const *argv[]) {
    return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}

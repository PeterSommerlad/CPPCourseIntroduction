#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

#include "charc.h"

#include <sstream>

void testCharcOnEmptyIstream() {
	std::istringstream input{};
	ASSERT_EQUAL(0u, charc(input));
}

void testCharcOnSingleLineIstream() {
	std::istringstream input{"single line"};
	ASSERT_EQUAL(10u, charc(input));
}

void testCharcOnMultiLineIstream() {
	std::istringstream input{"multi \n line\n  \n stream"};
	ASSERT_EQUAL(15u, charc(input));
}

void testCharcOnWhitespaceOnlyIstream() {
	std::istringstream input{"   \n\n\t\t   "};
	ASSERT_EQUAL(0u, charc(input));
}

bool runAllTests(int argc, char const *argv[]) {
	cute::suite s{};
	s.push_back(CUTE(testCharcOnEmptyIstream));
	s.push_back(CUTE(testCharcOnSingleLineIstream));
	s.push_back(CUTE(testCharcOnMultiLineIstream));
	s.push_back(CUTE(testCharcOnWhitespaceOnlyIstream));
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner = cute::makeRunner(lis, argc, argv);
	bool success = runner(s, "AllTests");
	return success;
}

int main(int argc, char const *argv[]) {
    return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}

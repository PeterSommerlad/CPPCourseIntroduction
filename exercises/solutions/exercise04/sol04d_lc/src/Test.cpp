#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

#include "lc.h"
#include <sstream>

void testsumionEmptyStream() {
	std::istringstream input{};
	ASSERT_EQUAL(0u, lc(input));
}

void testsumionSingleValueStream() {
	std::istringstream input{"single line\n"};
	ASSERT_EQUAL(1u, lc(input));
}

void testsumionMultipleValueStream() {
	std::istringstream input{"multi \n line\n  \n stream\n"};
	ASSERT_EQUAL(4u, lc(input));
}

void testsumionwhitespaceOnlyStream() {
	std::istringstream input{"   \n\n\t\t   \n"};
	ASSERT_EQUAL(3u, lc(input));
}

bool runAllTests(int argc, char const *argv[]) {
	cute::suite s{};
	s.push_back(CUTE(testsumionEmptyStream));
	s.push_back(CUTE(testsumionSingleValueStream));
	s.push_back(CUTE(testsumionMultipleValueStream));
	s.push_back(CUTE(testsumionwhitespaceOnlyStream));
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner = cute::makeRunner(lis, argc, argv);
	bool success = runner(s, "AllTests");
	return success;
}

int main(int argc, char const *argv[]) {
    return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}

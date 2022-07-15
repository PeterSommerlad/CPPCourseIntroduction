#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

#include "sumi.h"
#include <sstream>


void testsumionEmptyStream() {
	std::istringstream input{};
	ASSERT_EQUAL(0, sumi(input));
}

void testsumionSingleValueStream() {
	std::istringstream input{"42"};
	ASSERT_EQUAL(42, sumi(input));
}

void testsumionMultipleValueStream() {
	std::istringstream input{"1 2 3 4 5 6 7 8"};
	ASSERT_EQUAL(36, sumi(input));
}

void testsumionwhitespaceOnlyStream() {
	std::istringstream input{"   \n\n\t\t   \n"};
	ASSERT_EQUAL(0, sumi(input));
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

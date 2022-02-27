#include "kwic.h"
#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

#include <sstream>

void thisIsATest() {
	std::istringstream in{};
	std::ostringstream out{};
	kwic::kwic(in,out);
	ASSERT_EQUAL("",out.str());

}

void testTwoLines() {
	std::istringstream in{
			"this is a test\n"
			"this is another test\n"};
	std::ostringstream out{};
	kwic::kwic(in,out);
	ASSERT_EQUAL(R"(a test this is 
another test this is 
is a test this 
is another test this 
test this is a 
test this is another 
this is a test 
this is another test 
)"
	,out.str());
}
void testClarifyingExample() {
	std::istringstream in{R"(a b c d
a a b
b b c
)"};
	std::ostringstream out{};
	kwic::kwic(in,out);
	ASSERT_EQUAL(R"(a a b 
a b a 
a b c d 
b a a 
b b c 
b c b 
b c d a 
c b b 
c d a b 
d a b c 
)"
	,out.str());
}



bool runAllTests(int argc, char const *argv[]) {
	cute::suite s { };
	//TODO add your test here
	s.push_back(CUTE(thisIsATest));
	s.push_back(CUTE(testTwoLines));
	s.push_back(CUTE(testClarifyingExample));
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner = cute::makeRunner(lis, argc, argv);
	bool success = runner(s, "AllTests");
	return success;
}

int main(int argc, char const *argv[]) {
    return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}

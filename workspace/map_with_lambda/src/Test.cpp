#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

#include <algorithm>

#include <cctype>
#include <iterator>

#include <map>
#include <sstream>
#include <string>

void testCanPassWallIsFalse() {
	using namespace std::literals;
	auto const caselesscompare = [](auto l, auto r){
		return std::lexicographical_compare(std::begin(l),std::end(l),std::begin(r),std::end(r),
				[](char lc, char rc){ return std::tolower(lc)<std::tolower(rc);});};
	auto s = std::map<std::string,size_t,decltype(caselesscompare)>{caselesscompare};
	s.clear();
	std::istringstream in{"Hello hello Hello Peter PETER"};
    std::string str;
	while(in >> str){
		s[str]++;
	}
	ASSERT_EQUAL(2,s.size());
	ASSERT_EQUAL(2,s["peter"]);
	ASSERT_EQUAL(3,s["hello"]);
}

bool runAllTests(int argc, char const *argv[]) {
	cute::suite s { };
	//TODO add your test here
	s.push_back(CUTE(testCanPassWallIsFalse));
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner = cute::makeRunner(lis, argc, argv);
	bool success = runner(s, "AllTests");
	return success;
}

int main(int argc, char const *argv[]) {
    return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}

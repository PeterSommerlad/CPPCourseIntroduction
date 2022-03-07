#include "charcount.h"
#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

#include <string>
#include <sstream>

void emptyStreamCountsZeroCharc(){
	std::istringstream in{};
	ASSERT_EQUAL(0u,charc(in));
}

void oneCharStreamCountsOneCharc(){
	std::istringstream in{"a"};
	ASSERT_EQUAL(1u,charc(in));
}

void manyCharStreamCountsCharc(){
	//                     1 234567 890123  4567 890     12345
	std::istringstream in{"a longer stream\nwith new \n\tlines\n"};
	ASSERT_EQUAL(25u,charc(in));
}

void emptyStreamCountsZeroAllCharc(){
	std::istringstream in{};
	ASSERT_EQUAL(0u,allcharc(in));
}

void oneCharStreamCountsOneAllCharc(){
	std::istringstream in{"a"};
	ASSERT_EQUAL(1u,allcharc(in));
}

void manyCharStreamCountsAllCharc(){
	std::string const input{"a longer stream\nwith new \n\tlines\n"};
	std::istringstream in{input};
	ASSERT_EQUAL(input.size(),allcharc(in));
}
void emptyStreamCountsZeroWc(){
	std::istringstream in{};
	ASSERT_EQUAL(0u,wc(in));
}

void oneCharStreamCountsOneWc(){
	std::istringstream in{"a"};
	ASSERT_EQUAL(1u,wc(in));
}

void manyCharStreamCountsWc(){
	//                       1 2      3       4    5       6
	std::istringstream in{"a longer stream\nwith new \n\tlines\n"};
	ASSERT_EQUAL(6,wc(in));
}
void emptyStreamCountsZeroLc(){
	std::istringstream in{};
	ASSERT_EQUAL(0u,lc(in));
}

void onelineStreamCountsOneLc(){
	std::istringstream in{"\n"};
	ASSERT_EQUAL(1u,lc(in));
}

void manyLineStreamCountsLc(){
	//                                    1          2        3
	std::istringstream in{"a longer stream\nwith new \n\tlines\n"};
	ASSERT_EQUAL(3,lc(in));
}




bool runAllTests(int argc, char const *argv[]) {
	cute::suite s { };
	//TODO add your test here
	s.push_back(CUTE(emptyStreamCountsZeroCharc));
	s.push_back(CUTE(oneCharStreamCountsOneCharc));
	s.push_back(CUTE(manyCharStreamCountsCharc));
	s.push_back(CUTE(emptyStreamCountsZeroAllCharc));
	s.push_back(CUTE(oneCharStreamCountsOneAllCharc));
	s.push_back(CUTE(manyCharStreamCountsAllCharc));
	s.push_back(CUTE(emptyStreamCountsZeroWc));
	s.push_back(CUTE(oneCharStreamCountsOneWc));
	s.push_back(CUTE(manyCharStreamCountsWc));
	s.push_back(CUTE(emptyStreamCountsZeroLc));
	s.push_back(CUTE(onelineStreamCountsOneLc));
	s.push_back(CUTE(manyLineStreamCountsLc));
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner = cute::makeRunner(lis, argc, argv);
	bool success = runner(s, "AllTests");
	return success;
}

int main(int argc, char const *argv[]) {
    return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}

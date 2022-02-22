#include "Counter.h"
#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

#include <sstream>

void CounterConstruction() {
	first::Counter c{42};
	ASSERT_EQUAL(42,c.theCount);
}

void CounterDefaultConstruction(){
	first::Counter c{};
	ASSERT_EQUAL(0, c.theCount);
}

void CounterIncrementIncrementsByOneFromZero() {
	first::Counter c{};
	increment(c);
	ASSERT_EQUAL(1, c.theCount);
}

void CounterIncrementIncrementsByOne() {
	first::Counter c{42};
	increment(c);
	ASSERT_EQUAL(43, c.theCount);
}

void CounterCanPrintItsValue(){
	std::ostringstream out{};
	first::Counter const c { 5 };
	print(out,c);
	ASSERT_EQUAL("5",out.str());
}
namespace test_second {
void CounterConstruction() {
	second::Counter c{42};
	ASSERT_EQUAL(42,c.theCount);
}

void CounterDefaultConstruction(){
	second::Counter c{};
	ASSERT_EQUAL(0, c.theCount);
}

void CounterIncrementIncrementsByOneFromZero() {
	second::Counter c{};
	c.increment();
	ASSERT_EQUAL(1, c.theCount);
}

void CounterIncrementIncrementsByOne() {
	second::Counter c{42};
	c.increment();
	ASSERT_EQUAL(43, c.theCount);
}

void CounterCanPrintItsValue(){
	std::ostringstream out{};
	second::Counter const c { 5 };
	c.print(out);
	ASSERT_EQUAL("5",out.str());
}

}

namespace test_third {
using third::Counter;
void CounterConstruction() {
	Counter c{42};
	ASSERT_EQUAL(Counter{42},c);
	// uses operator==
}

void CounterDefaultConstruction(){
	Counter c{};
	ASSERT_EQUAL(Counter{0}, c);
}

void CounterIncrementIncrementsByOneFromZero() {
	Counter c{};
	c.increment();
	ASSERT_EQUAL(Counter{1}, c);
}

void CounterIncrementIncrementsByOne() {
	Counter c{42};
	c.increment();
	ASSERT_EQUAL(Counter{43}, c);
}

void CounterCanPrintItsValue(){
	std::ostringstream out{};
	Counter const c { 5 };
	c.print(out);
	ASSERT_EQUAL("5",out.str());
}

}

namespace test_fourth {
using fourth::Counter;
void CounterConstruction() {
	Counter c{42};
	ASSERT_EQUAL(Counter{42},c);
}

void CounterDefaultConstruction(){
	Counter c{};
	ASSERT_EQUAL(Counter{0}, c);
}

void CounterIncrementIncrementsByOneFromZero() {
	Counter c{};
	ASSERT_EQUAL(Counter{},c++);
	ASSERT_EQUAL(Counter{1}, c);
}

void CounterIncrementIncrementsByOne() {
	Counter c{42};
	++c;
	ASSERT_EQUAL(Counter{44}, ++c);
}

void CounterCanPrintItsValue(){
	std::ostringstream out{};
	Counter const c { 5 };
	out << c;
	ASSERT_EQUAL("5",out.str());
}

}

bool runAllTests(int argc, char const *argv[]) {
	cute::suite s { };
	//TODO add your test here
	s.push_back(CUTE(CounterConstruction));
	s.push_back(CUTE(CounterDefaultConstruction));
	s.push_back(CUTE(CounterIncrementIncrementsByOneFromZero));
	s.push_back(CUTE(CounterIncrementIncrementsByOne));
	s.push_back(CUTE(CounterCanPrintItsValue));
	s.push_back(CUTE(test_second::CounterConstruction));
	s.push_back(CUTE(test_second::CounterDefaultConstruction));
	s.push_back(CUTE(test_second::CounterIncrementIncrementsByOneFromZero));
	s.push_back(CUTE(test_second::CounterIncrementIncrementsByOne));
	s.push_back(CUTE(test_second::CounterCanPrintItsValue));
	s.push_back(CUTE(test_third::CounterConstruction));
	s.push_back(CUTE(test_third::CounterDefaultConstruction));
	s.push_back(CUTE(test_third::CounterIncrementIncrementsByOneFromZero));
	s.push_back(CUTE(test_third::CounterIncrementIncrementsByOne));
	s.push_back(CUTE(test_third::CounterCanPrintItsValue));
	s.push_back(CUTE(test_fourth::CounterConstruction));
	s.push_back(CUTE(test_fourth::CounterDefaultConstruction));
	s.push_back(CUTE(test_fourth::CounterIncrementIncrementsByOneFromZero));
	s.push_back(CUTE(test_fourth::CounterIncrementIncrementsByOne));
	s.push_back(CUTE(test_fourth::CounterCanPrintItsValue));
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner = cute::makeRunner(lis, argc, argv);
	bool success = runner(s, "AllTests");
	return success;
}

int main(int argc, char const *argv[]) {
    return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}

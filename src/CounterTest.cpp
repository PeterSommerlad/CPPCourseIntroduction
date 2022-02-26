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
using third::Counter; // Counter visible
void CounterConstruction() {
  Counter c{42};
  ASSERT_EQUAL(Counter{42},c);
  // uses operator==
}
void CounterDefaultConstruction(){
  Counter c{};
  ASSERT_EQUAL(Counter{0}, c);
  // uses operator==
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



namespace test_fifth {
using fifth::Counter;
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


void CounterCanCompareLess() {
  ASSERT(Counter{} < Counter{1});
}
void CounterCanCompareLessEqual() {
  ASSERT(Counter{} <= Counter{1});
}
void CounterCanCompareGreater() {
  ASSERT(Counter{2} > Counter{1});
}
void CounterCanCompareGreaterEqual() {
  ASSERT(Counter{2} >= Counter{1});
}


}

namespace ExtendedCounterTest {
using fifth::DecrementableCounter;
void CounterConstruction() {
  DecrementableCounter c{42};
  ASSERT_EQUAL(DecrementableCounter{42},c);
}

void CounterDefaultConstruction(){
  DecrementableCounter c{};
  ASSERT_EQUAL(DecrementableCounter{0}, c);
}

void CounterIncrementIncrementsByOneFromZero() {
  DecrementableCounter c{};
  ASSERT_EQUAL(DecrementableCounter{0}, c++);
  ASSERT_EQUAL(DecrementableCounter{1}, c);
}

void CounterIncrementIncrementsByOne() {
  DecrementableCounter c{42};
  DecrementableCounter const expect{44};
  ++c;
  ASSERT_EQUAL(expect, ++c);
}
void CounterCanPrintItsValue(){
  std::ostringstream out{};
  DecrementableCounter const c { 5 };
  out << c;
  ASSERT_EQUAL("5",out.str());
}


void CounterCanCompareLess() {
  ASSERT(DecrementableCounter{} < DecrementableCounter{1});
}
void CounterCanCompareLessEqual() {
  ASSERT(DecrementableCounter{} <= DecrementableCounter{1});
}
void CounterCanCompareGreater() {
  ASSERT(DecrementableCounter{2} > DecrementableCounter{1});
}
void CounterCanCompareGreaterEqual() {
  ASSERT(DecrementableCounter{2} >= DecrementableCounter{1});
}
void CounterIncrementDecrementsByOneToZero() {
  DecrementableCounter c{1};
  ASSERT_EQUAL(DecrementableCounter{1}, c--);
  ASSERT_EQUAL(DecrementableCounter{0}, c);
}
void CounterIncrementDecrementsByOne() {
  DecrementableCounter c{42};
  --c;
  ASSERT_EQUAL(DecrementableCounter{40}, --c);
}



}

namespace test_second_separate_impl {
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
  s.push_back(CUTE(test_fifth::CounterConstruction));
  s.push_back(CUTE(test_fifth::CounterDefaultConstruction));
  s.push_back(CUTE(test_fifth::CounterIncrementIncrementsByOneFromZero));
  s.push_back(CUTE(test_fifth::CounterIncrementIncrementsByOne));
  s.push_back(CUTE(test_fifth::CounterCanPrintItsValue));
  s.push_back(CUTE(test_fifth::CounterCanCompareLess));
  s.push_back(CUTE(test_fifth::CounterCanCompareLessEqual));
  s.push_back(CUTE(test_fifth::CounterCanCompareGreater));
  s.push_back(CUTE(test_fifth::CounterCanCompareGreaterEqual));
  s.push_back(CUTE(ExtendedCounterTest::CounterConstruction));
  s.push_back(CUTE(ExtendedCounterTest::CounterDefaultConstruction));
  s.push_back(CUTE(ExtendedCounterTest::CounterIncrementIncrementsByOneFromZero));
  s.push_back(CUTE(ExtendedCounterTest::CounterIncrementIncrementsByOne));
  s.push_back(CUTE(ExtendedCounterTest::CounterCanPrintItsValue));
  s.push_back(CUTE(ExtendedCounterTest::CounterCanCompareLess));
  s.push_back(CUTE(ExtendedCounterTest::CounterCanCompareLessEqual));
  s.push_back(CUTE(ExtendedCounterTest::CounterCanCompareGreater));
  s.push_back(CUTE(ExtendedCounterTest::CounterCanCompareGreaterEqual));
  s.push_back(CUTE(ExtendedCounterTest::CounterIncrementDecrementsByOneToZero));
  s.push_back(CUTE(ExtendedCounterTest::CounterIncrementDecrementsByOne));
	s.push_back(CUTE(test_second_separate_impl::CounterConstruction));
	s.push_back(CUTE(test_second_separate_impl::CounterDefaultConstruction));
	s.push_back(CUTE(test_second_separate_impl::CounterIncrementIncrementsByOneFromZero));
	s.push_back(CUTE(test_second_separate_impl::CounterIncrementIncrementsByOne));
	s.push_back(CUTE(test_second_separate_impl::CounterCanPrintItsValue));
  cute::xml_file_opener xmlfile(argc, argv);
  cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
  auto runner = cute::makeRunner(lis, argc, argv);
  bool success = runner(s, "AllTests");
  return success;
}

int main(int argc, char const *argv[]) {
    return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}

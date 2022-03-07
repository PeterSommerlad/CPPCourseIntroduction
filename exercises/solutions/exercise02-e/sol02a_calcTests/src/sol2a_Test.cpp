#include "calc.h"
#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

void onePlusOneShouldBeTwo() {
	ASSERT_EQUAL(calc(1, 1, '+'), 2);
}

void minusOnePlusOneShouldBeZero() {
	ASSERT_EQUAL(calc(-1, 1, '+'), 0);
}

void threePlusTenShouldBe13() {
	ASSERT_EQUAL(calc(3, 10, '+'), 13);
}

void oneMinusOneShouldBeZero() {
	ASSERT_EQUAL(calc(1, 1, '-'), 0);
}

void minusOneMinusOneShouldBeMinusTwo() {
	ASSERT_EQUAL(calc(-1, 1, '-'), -2);
}

void threeMinusMinusTenShouldBe13() {
	ASSERT_EQUAL(calc(3, -10, '-'), 13);
}

void threeMultMinusTenShouldBeMinus30() {
	ASSERT_EQUAL(calc(3, -10, '*'), -30);
}

void threeMultTenShouldBe30() {
	ASSERT_EQUAL(calc(3, 10, '*'), 30);
}

void nineDividedByThreeShouldBeThree() {
	ASSERT_EQUAL(calc(9, 3, '/'), 3);
}

void minusNineDividedByThreeShouldEqualMinusThree() {
	ASSERT_EQUAL(calc(-9, 3, '/'), -3);
}

void twoModulotwoShouldBeZero() {
	ASSERT_EQUAL(calc(2, 2, '%'), 0);
}

void threeModulotwoShouldBeOne() {
	ASSERT_EQUAL(calc(3, 2, '%'), 1);
}

void threeModuloZeroShouldThrowExceptionShouldBeOne() {
	//ASSERT_EQUAL(calc(3, 2, '%'), 1);
}

void nineDivideZeroShouldThrowException() {
//	ASSERT_EQUAL(calc(9, 0, '/'), "todo");
}

void computeFromStream(){
	  std::istringstream input{"95/5"};
	  auto result = calc(input);
	  ASSERT_EQUAL(19,result);
}


bool runAllTests(int argc, char const *argv[]) {
	cute::suite s { };
	//TODO add your test here
	s.push_back(CUTE(onePlusOneShouldBeTwo));
	s.push_back(CUTE(minusOnePlusOneShouldBeZero));
	s.push_back(CUTE(threePlusTenShouldBe13));
	s.push_back(CUTE(oneMinusOneShouldBeZero));
	s.push_back(CUTE(minusOneMinusOneShouldBeMinusTwo));
	s.push_back(CUTE(threeMultMinusTenShouldBeMinus30));
	s.push_back(CUTE(threeMultTenShouldBe30));
	s.push_back(CUTE(nineDividedByThreeShouldBeThree));
	s.push_back(CUTE(minusNineDividedByThreeShouldEqualMinusThree));
	s.push_back(CUTE(twoModulotwoShouldBeZero));
	s.push_back(CUTE(threeModulotwoShouldBeOne));
	s.push_back(CUTE(threeMinusMinusTenShouldBe13));
	s.push_back(CUTE(computeFromStream));
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner = cute::makeRunner(lis, argc, argv);
	bool success = runner(s, "AllTests");
	return success;
}

int main(int argc, char const *argv[]) {
    return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}

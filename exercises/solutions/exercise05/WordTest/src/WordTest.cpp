#include "Word.h"
#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

#include <sstream>

using text::Word;

void test_cannot_create_empty_word() {
	ASSERT_THROWS(Word { "" }, std::invalid_argument);
}

void test_cannot_create_word_with_space() {
	ASSERT_THROWS(Word { "abc xyz" }, std::invalid_argument);
}

void test_cannot_create_word_with_number() {
	ASSERT_THROWS(Word { "abc3xyz" }, std::invalid_argument);
}

void test_cannot_create_word_with_punctuation() {
	ASSERT_THROWS(Word { "abc.xyz" }, std::invalid_argument);
}

void test_output_operator() {
	std::string const expected { "Python" };
	Word const w { expected };
	std::ostringstream output { };
	output << w;
	ASSERT_EQUAL(expected, output.str());
}

void test_same_words_are_equal() {
	ASSERT_EQUAL(Word { "Ruby" }, Word { "Ruby" });
}

void test_different_words_are_not_equal() {
	ASSERT_NOT_EQUAL_TO(Word{"Haskell"}, Word{"ML"});
}

void test_same_word_with_different_cases_are_equal() {
	ASSERT_EQUAL(Word { "BASIC" }, Word { "basic" });
}

void test_same_word_is_not_lower_than() {
	ASSERT(!(Word { "Erlang" } < Word { "Erlang" }));
}

void test_smaller_word_is_smaller() {
	ASSERT_LESS(Word { "Erlang" }, Word { "Fortran" });
}

void test_smaller_word_with_capital_letters_is_smaller() {
	ASSERT_LESS(Word { "ADA" }, Word { "java" });
}

void test_same_word_with_different_cases_are_not_smaller() {
	ASSERT(!(Word {"Groovy"} < Word {"groovy"}));
}

void test_greater_word_is_greater() {
	ASSERT_GREATER(Word { "Rust" }, Word { "Prolog" });
}

void test_greater_word_with_capital_letters_is_greater() {
	ASSERT_GREATER(Word { "Lisp" }, Word { "brainfuck" });
}

void test_smaller_word_is_less_equal() {
	ASSERT_LESS_EQUAL(Word { "Algol" }, Word { "BCPL" });
}

void test_same_word_is_less_equal() {
	ASSERT_LESS_EQUAL(Word { "Assembler" }, Word { "Assembler" });
}

void test_greater_word_is_greater_equal() {
	ASSERT_GREATER_EQUAL(Word { "RPG" }, Word { "Perl" });
}

void test_same_word_is_greater_equal() {
	ASSERT_GREATER_EQUAL(Word { "Scala" }, Word { "Scala" });
}

void test_input_operator_single_word() {
	std::istringstream input{"Elixir"};
	Word w{};
	input >> w;
	ASSERT_EQUAL(Word{"Elixir"}, w);
}

void test_input_operator_single_word_stream_good() {
	std::istringstream input{"Cobol"};
	Word w{};
	ASSERT(input >> w);
}

void test_input_operator_called_once_first_word() {
	std::istringstream input{"Ceylon Go"};
	Word w{};
	input >> w;
	ASSERT_EQUAL(Word{"Ceylon"}, w);
}

void test_input_operator_called_once_stream_good() {
	std::istringstream input{"Lua Oberon"};
	Word w{};
	ASSERT(input >> w);
}

void test_input_operator_on_empty_stream_fail() {
	std::istringstream input{};
	Word w{};
	input >> w;
	ASSERT(input.fail());
}

void test_input_operator_on_stream_without_word() {
	std::istringstream input{"1337"};
	Word w{};
	input >> w;
	ASSERT(input.fail());
}

void test_input_operator_on_empty_stream_word_unchanged() {
	std::istringstream input{};
	Word w{"Eiffel"};
	input >> w;
	ASSERT_EQUAL(Word{"Eiffel"}, w);
}

void test_input_operator_stops_on_slash() {
	std::istringstream input{"PL/SQL"};
	Word w{};
	input >> w;
	ASSERT_EQUAL(Word{"PL"}, w);
}

void test_input_operator_stops_at_end_of_word() {
	std::istringstream input{"VB6"};
	Word w{};
	int i{};
	input >> w >> i;
	ASSERT_EQUAL(6, i);
}

void test_input_operator_skips_leading_non_alpha() {
	std::istringstream input{"3switchBF"};
	Word w{};
	input >> w;
	ASSERT_EQUAL(Word{"switchBF"}, w);
}

void test_input_operator_overwrites_word() {
	std::istringstream input{"Kotlin"};
	Word w{"JavaScript"};
	input >> w;
	ASSERT_EQUAL(Word{"Kotlin"}, w);
}

void test_exercise_example() {
	std::istringstream input{"compl33tely ~ weird !!??!! 4matted in_put"};
	Word w{};
	input >> w;
	ASSERT_EQUAL(Word{"compl"}, w);
	input >> w;
	ASSERT_EQUAL(Word{"tely"}, w);
	input >> w;
	ASSERT_EQUAL(Word{"weird"}, w);
	input >> w;
	ASSERT_EQUAL(Word{"matted"}, w);
	input >> w;
	ASSERT_EQUAL(Word{"in"}, w);
	input >> w;
	ASSERT_EQUAL(Word{"put"}, w);
	input >> w;
	ASSERT_EQUAL(Word{"put"}, w);
}

bool runAllTests(int argc, char const *argv[]) {
	cute::suite s { };
	s.push_back(CUTE(test_cannot_create_empty_word));
	s.push_back(CUTE(test_cannot_create_word_with_space));
	s.push_back(CUTE(test_cannot_create_word_with_number));
	s.push_back(CUTE(test_cannot_create_word_with_punctuation));
	s.push_back(CUTE(test_output_operator));
	s.push_back(CUTE(test_same_words_are_equal));
	s.push_back(CUTE(test_different_words_are_not_equal));
	s.push_back(CUTE(test_same_word_with_different_cases_are_equal));
	s.push_back(CUTE(test_same_word_is_not_lower_than));
	s.push_back(CUTE(test_smaller_word_is_smaller));
	s.push_back(CUTE(test_smaller_word_with_capital_letters_is_smaller));
	s.push_back(CUTE(test_same_word_with_different_cases_are_not_smaller));
	s.push_back(CUTE(test_greater_word_is_greater));
	s.push_back(CUTE(test_greater_word_with_capital_letters_is_greater));
	s.push_back(CUTE(test_smaller_word_is_less_equal));
	s.push_back(CUTE(test_same_word_is_less_equal));
	s.push_back(CUTE(test_greater_word_is_greater_equal));
	s.push_back(CUTE(test_same_word_is_greater_equal));
	s.push_back(CUTE(test_input_operator_single_word));
	s.push_back(CUTE(test_input_operator_single_word_stream_good));
	s.push_back(CUTE(test_input_operator_called_once_first_word));
	s.push_back(CUTE(test_input_operator_called_once_stream_good));
	s.push_back(CUTE(test_input_operator_on_empty_stream_fail));
	s.push_back(CUTE(test_input_operator_on_stream_without_word));
	s.push_back(CUTE(test_input_operator_on_empty_stream_word_unchanged));
	s.push_back(CUTE(test_input_operator_stops_on_slash));
	s.push_back(CUTE(test_input_operator_stops_at_end_of_word));
	s.push_back(CUTE(test_input_operator_skips_leading_non_alpha));
	s.push_back(CUTE(test_input_operator_overwrites_word));
	s.push_back(CUTE(test_exercise_example));
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner { cute::makeRunner(lis, argc, argv) };
	bool success = runner(s, "AllTests");
	return success;
}


int main(int argc, char const *argv[]) {
	return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}

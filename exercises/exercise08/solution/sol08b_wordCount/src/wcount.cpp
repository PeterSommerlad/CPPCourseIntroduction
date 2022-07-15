#include "wcount.h"
#include <istream>
#include <iterator>
#include "sol08b_word.h"

unsigned wcount(std::istream& in) {
	using word_iterator = std::istream_iterator<word::Word>;
	return std::distance(word_iterator{in}, word_iterator{});
}

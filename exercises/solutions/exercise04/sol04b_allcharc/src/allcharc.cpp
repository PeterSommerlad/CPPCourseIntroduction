#include "allcharc.h"

#include <istream>
#include <iterator>

size_t allcharc(std::istream &in) {
	using input = std::istreambuf_iterator<char>;
	input eof{};
	return distance(input{in}, eof);
}

#include "lc.h"

#include <algorithm>

#include <istream>
#include <iterator>

size_t lc(std::istream &in) {
	using input=std::istreambuf_iterator<char>;
	input eof{};
	return count(input(in),eof,'\n');
}

#include "wc.h"

#include <istream>
#include <string>
#include <iterator>

size_t wc(std::istream &in) {
	using input=std::istream_iterator<std::string>;
	input eof{};

	return distance(input(in),eof);
}

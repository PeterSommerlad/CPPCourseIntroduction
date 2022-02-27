#include "charc.h"

#include <istream>
#include <iterator>


size_t charc(std::istream &in) {
	using input=std::istream_iterator<char>;
	input eof{};
	//TODO: Implement without loops
	return distance(input(in),eof);
}

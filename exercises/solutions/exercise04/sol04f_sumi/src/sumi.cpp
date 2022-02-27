#include "sumi.h"
#include <istream>
#include <iterator>
#include <numeric>
int sumi(std::istream &is) {
	using input=std::istream_iterator<int>;
	input eof{};
	return std::reduce(input{is},eof,0);
}

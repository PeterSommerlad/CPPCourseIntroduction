#include "charcount.h"
#include <istream>
#include <string>
#include <iterator>
#include <algorithm>

unsigned charc(std::istream &in) {
	using it = std::istream_iterator<char>;
	return distance(it{in},it{});
}

unsigned allcharc(std::istream &in) {
	using it = std::istreambuf_iterator<char>;
	return distance(it{in},it{});
}

unsigned wc(std::istream &in) {
	using it = std::istream_iterator<std::string>;
	return distance(it{in},it{});
}

unsigned lc(std::istream &in) {
	using it = std::istreambuf_iterator<char>;
	return count(it{in},it{},'\n');
}

#include "Word.h"

#include <algorithm>
#include <iterator>

#include <stdexcept>
#include <cctype>
#include <string>

namespace text {

// DIY stream manipulator
std::istream &skip_nonalpha(std::istream &in){
	while(in && ! std::isalpha(in.peek())){
		std::ignore = in.get();
	}
	return in;
}

void Word::read(std::istream &in) & {
	if (in >> skip_nonalpha) {
		word.clear();
		while(in && std::isalpha(in.peek()	)){
			word.push_back(in.get());
		}
	} else {
		in.setstate(std::ios::failbit);
	}
}

Word::Word(std::string s) : word{s} {
	if (s.empty()) throw std::invalid_argument{"Word(string): empty string given"};
	if (not std::all_of(begin(s),end(s),[](char c) { return std::isalpha(c);}))
		throw std::invalid_argument{"Word(string): non-alpha character in word"};
}

} /* namespace text */

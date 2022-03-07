#include "Word.h"

#include <algorithm>
#include <iterator>

#include <stdexcept>
#include <cctype>
#include <string>

namespace text {

void Word::read(std::istream &in) {
	char c{};
	while(in && ! std::isalpha(c)){
		in.get(c);
	}
	if (!std::isalpha(c)) {
		in.setstate(std::ios::failbit);
		return;
	}
	word.clear();
	word.push_back(c);
	while(in && std::isalpha(in.peek()	)){
		in.get(c);
		word.push_back(c);
	}
	if (!in && !word.empty()){
		in.clear(); // might have read into eof, but still successful for the word
	}
}

Word::Word(std::string s) : word{s} {
	if (s.empty()) throw std::invalid_argument{"Word(string): empty string given"};
	if (not std::all_of(begin(s),end(s),[](char c) { return std::isalpha(c);}))
		throw std::invalid_argument{"Word(string): non-alpha character in word"};
}

} /* namespace text */

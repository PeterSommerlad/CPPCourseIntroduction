#include "Word.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <set> // variant with std:set

int main(){
	using text::Word;
	using in=std::istream_iterator<Word>;
	std::set<Word> wlist { in { std::cin }, in { } };// requires <Word> for finding operator<
	std::copy(begin(wlist),end(wlist),
		 std::ostream_iterator<Word> { std::cout, "\n" });
}
// https://godbolt.org/z/oT13dMWv7

#include <string>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <cctype>
#include <vector> // variant with algorithms
#include <set> // variant with std:set

int main(){
	using in=std::istream_iterator<std::string>;
	auto const caselesslessstring { [] (std::string const &l, std::string const& r){
    	return lexicographical_compare(begin(l),end(l),begin(r),end(r),
    			[] (char l, char r){ return std::tolower(l) < std::tolower(r);});
    }};
#if 1
	// https://godbolt.org/z/3rvPMqcnf
    auto const caselessequalstring { [] (std::string const &l, std::string const &r){
    	return equal(begin(l),end(l),begin(r),end(r),
    			[] (char l, char r){ return std::tolower(l) == std::tolower(r);});
    }};
	std::vector<std::string> wlist{in{std::cin},in{}};
	sort(begin(wlist),end(wlist),caselesslessstring);
	wlist.erase(unique(begin(wlist),end(wlist),caselessequalstring), end(wlist));
#else
	// https://godbolt.org/z/jcGTWd1or
	std::set wlist{in{std::cin},in{},caselesslessstring};
#endif
	copy(begin(wlist),end(wlist),
		 std::ostream_iterator<std::string>{std::cout,"\n"});
}

#include "word.h"

#include <algorithm>
#include <stdexcept>
#include <istream>
#include <ostream>
#include <cctype>
bool invariantViolated(std::string const &w){
	return (w.empty()
	   ||count_if(w.begin(),w.end(),[](char c){return !isalpha(c);}));
}
namespace word{
Word::Word(std::string const &word):w{word}{
	if (invariantViolated(w))
		throw std::logic_error{"Invalid word characters"};
}
std::ostream& Word::print(std::ostream& out) const {
	out << w;
	return out;
}
std::istream& Word::read(std::istream& in) {
	std::string newword{};
	char c{};
	while (in.get(c) && !isalpha(c));
	while (isalpha(c)){
		newword += c;
		if (!in.get(c)) break;
	}
	if (invariantViolated(newword))
		 in.clear(std::ios::failbit);
	else {
		w=newword;
		if (in.eof()) in.clear(); // might have read into stream eof, but still got a word
	}
	return in;
}
bool Word::stringcaselessequal(std::string const &w, std::string const &other){
	size_t len=std::min(w.size(),other.size());
	return std::equal(w.begin(),w.begin()+len,other.begin(),
						[](char l, char r){
							return tolower(l) == tolower(r);
						});

}
bool Word::stringcaselessless(std::string const &w, std::string const &other){
	return std::lexicographical_compare(w.begin(),w.end(),
										other.begin(),other.end(),
										[](char l, char r){
											return tolower(l) < tolower(r);
										});
}
}

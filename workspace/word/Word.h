#ifndef SRC_WORD_H_
#define SRC_WORD_H_

#if __cplusplus >= 202000L
#include <compare>
#endif

#include <algorithm>
#include <cctype>
#include <iterator>
#include <string>
#include <ostream>
#include <istream>
namespace text {

class Word {
	std::string word{};
	void read(std::istream &in) &;
public:
	explicit Word(std::string);
	Word()=default;

friend
std::ostream& operator<<(std::ostream& out, Word const &w){
	return out << w.word;
}

friend
std::istream& operator>>(std::istream& in, Word &w){
	w.read(in);
	return in;
}
#if __cplusplus >= 202000L
auto operator<=>( Word const &r ) const {
	return std::lexicographical_compare_three_way(begin(word),end(word),begin(r.word),end(r.word),
      [](char lc,char rc){return std::tolower(lc) <=> std::tolower(rc);});
}
bool operator==( Word const &r ) const {
	return std::is_eq(*this <=> r);
}
#else
friend bool
operator==(Word const&l, Word const &r){
	return equal(begin(l.word),end(l.word),begin(r.word),end(r.word),
      [](char lc,char rc){return std::tolower(lc)==std::tolower(rc);});
}
friend bool
operator!=(Word const&l, Word const &r){
	return !(l == r);
}

friend bool
operator<(Word const&l, Word const &r){
	return std::lexicographical_compare(begin(l.word),end(l.word),begin(r.word),end(r.word),
      [](char lc,char rc){return std::tolower(lc) < std::tolower(rc);});
}
friend bool
operator>(Word const&l, Word const &r){
	return r < l;
}
friend bool
operator<=(Word const&l, Word const &r){
	return !(l > r);
}
friend bool
operator>=(Word const&l, Word const &r){
	return !(l < r);
}
#endif
};


} /* namespace text */

#endif /* SRC_WORD_H_ */

#ifndef WORD_H_
#define WORD_H_
#include <iosfwd>
#include <string>
namespace word{
struct Word {
	Word()=default; // allow empty words for storing in vector.
	Word(std::string const &word);
	bool operator==(Word const &other) const {
		return stringcaselessequal(w,other.w);
	}
	bool operator<(Word const &other) const {
		return stringcaselessless(w,other.w);
	}
	std::ostream& print(std::ostream& out) const;
	std::istream& read(std::istream& in);
private:
	static bool stringcaselessequal(std::string const &w, std::string const &other);
	static bool stringcaselessless(std::string const &w, std::string const &other);
	std::string w;
};

inline bool operator==(char const *l, Word const &r){
	return (Word(l)==r);
}
inline bool operator<(char const *l, Word const &r){
	return (Word{l}<r);
}
inline bool operator!=(Word const & l, Word const &r){
	return !(l==r);
}
inline bool operator>(Word const &l, Word const &r){
	return r < l;
}
inline bool operator>=(Word const &l, Word const &r){
	return !(l<r);
}
inline bool operator<=(Word const &l, Word const &r){
	return !(r < l);
}
inline bool operator>(char const *l, Word const &r){
	return (Word{l}>r);
}

inline std::ostream &operator<<(std::ostream &out,Word const &w){
	return w.print(out);
}
inline std::istream &operator>>(std::istream &in, Word &w){
	return w.read(in);
}
}
#endif /* WORD_H_ */

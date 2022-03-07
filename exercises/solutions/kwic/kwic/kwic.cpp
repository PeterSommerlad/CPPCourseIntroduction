#include "kwic.h"

#include "word.h"
#include <istream>
#include <ostream>
// implement key-word in context KWIC problem as described by Parnas
#include <algorithm>
#include <iterator>
#include <vector>
#include <set>
#include <sstream>
#include <string>

namespace {
using word::Word;
//using sentence=std::vector<Word>;
// with inheriting constructors can define own type easily to avoid problems with ADL
struct sentence:std::vector<Word>{
	using std::vector<Word>::vector;
};

std::ostream& operator<<(std::ostream &os,sentence const &s){
	std::copy(s.begin(),s.end(),std::ostream_iterator<Word>(os," "));
	return os;
}
std::istream& operator>>(std::istream &is,sentence &s){
	using std::string;
	using std::istringstream;
	using input=std::istream_iterator<Word>;
	string line;
	if (getline(is,line)){
		s.clear();
		istringstream forSplit{line};
		copy(input{forSplit},input{},back_inserter(s));
	}
	return is;
}

struct collect_rotations{
	std::set<sentence> result;
	void operator()(sentence const &s){
		for(auto i=s.begin(); i < s.end(); ++i){
			sentence rotated(s.size()); // {} would work here
			rotate_copy(s.begin(),i,s.end(),rotated.begin());
			result.insert(rotated);
		}
	}
};

}
namespace kwic {

void kwic(std::istream& in, std::ostream& out) {
	std::vector<sentence> sentences{};
	using inputsentence=std::istream_iterator<sentence>;
	copy(inputsentence{in},inputsentence{},back_inserter(sentences));
	auto result = for_each(sentences.begin(),sentences.end(),collect_rotations{}).result;
	copy(result.begin(),result.end(),std::ostream_iterator<sentence>{out,"\n"});
}

}

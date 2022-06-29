#include "charcount.h"

#include <ios>
#include <istream>
#include <string>

unsigned charc(std::istream &in) {
	unsigned count{};
	char c{};
	while(in >> c){
		++count;
	}
	return count;
}

unsigned allcharc(std::istream &in) {
	unsigned count{};
	char c{};
	in >> std::noskipws;
	while(in && in >> c){
		++count;
	}
	return count;
}

unsigned wc(std::istream &in) {
	unsigned count{};
	std::string s{};
	while(in && in >> s){
		++count;
	}
	return count;
}

unsigned lc(std::istream &in) {
	unsigned count{};
	char c{};
	std::string line{};
	//while(in && in.get(c)){
    while(in && getline(in,line)){
		//if (c == '\n'){
			++count;
		//}
	}
	return count;
}

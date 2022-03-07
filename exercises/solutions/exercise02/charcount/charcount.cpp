#include "charcount.h"
#include <istream>
#include <string>

unsigned charc(std::istream &in) {
	unsigned count{};
	char c{};
	while(in && in >> c){
		++count;
	}
	return count;
}

unsigned allcharc(std::istream &in) {
	unsigned count{};
	char c{};
	while(in && in.get(c)){
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
	while(in && in.get(c)){
		if (c == '\n'){
			++count;
		}
	}
	return count;
}

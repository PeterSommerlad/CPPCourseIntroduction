#include "calc.h"
#include <istream>

#include <map>
#include <functional>

#if 0 // show off implementation using function objects

using namespace std;

map<char, function<int(int, int)>> const operators = { { '+', plus<int>{} }, { '-', minus<int>{} }, { '*', multiplies<int>() },
		{ '/', divides<int>{} }, { '%', modulus<int>{} } };

int calc(int const number1, int const number2, char const op) {
	return operators.at(op)(number1, number2);
}

#else

int calc(int l, int r, char op) {
	switch(op){
	case '+': return l + r;
	case '-': return l - r;
	case '*': return l * r;
	case '/': return r!=0? l / r : 0;
	case '%': return r!=0? l % r : 0;
	default: ; // could throw to mark error
	}
	return 0; // invalid op
}


#endif
int calc(std::istream &in) {
	int l{};
	int r{};
	char c{};
	if (in >> l >> c >> r) {
		return calc(l,r,c);
	}
	in.clear();
	return 0; // could throw
}

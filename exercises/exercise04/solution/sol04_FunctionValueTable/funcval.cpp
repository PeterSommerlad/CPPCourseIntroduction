#include "funcval.h"
#include <vector>
#include <algorithm>
#include <ostream>
#include <iterator>

void printFunctionTable(std::ostream &out, double const b, double const e, int const steps, double func(double)) {
	auto const v { generateValueList(b, e, steps)};
	out << "x\t";
	std::ostream_iterator<double> oi{out,"\t"};
	copy(begin(v),end(v),oi);
	out << "\nf(x)\t";
	transform(begin(v),end(v),oi,func);
	out << "\n";
}

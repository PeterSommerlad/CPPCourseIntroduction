#ifndef FUNCVAL_H_
#define FUNCVAL_H_
#include <iosfwd>
#include <vector>
#include <algorithm>
inline
std::vector<double> generateValueList(double begin, double end, unsigned steps) {
	if (steps > 1) {
		std::vector<double> result(steps); /// cannot use {steps}
		auto const delta = (end - begin) / (steps - 1);
		generate(result.begin(), result.end(), [begin, delta, i = 0]() mutable {
			return begin + (i++ * delta);
		}
		);
		return result;
	} else {
		return {};
	}
}

void printFunctionTable(std::ostream& out,
		                double b, double e, int steps,
						double func(double));

#endif /* FUNCVAL_H_ */

#ifndef FUNCVAL_H_
#define FUNCVAL_H_
#include <iosfwd>
void printFunctionTable(std::ostream& out,
		                double b, double const e, int const steps,
						double func(double));

#endif /* FUNCVAL_H_ */

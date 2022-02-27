
#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>



int main() {
	auto const limit = 10;
	std::vector<int> v(limit);
	std::iota(begin(v),end(v),1);
	for_each(cbegin(v),cend(v),
			[&v](int row){
				std::cout << std::setprecision(5) << std::setw(10) <<std::fixed;
				std::ostream_iterator<double> out{std::cout," "};
				transform(cbegin(v),cend(v),out,[row](double col){return row/col;});
				std::cout <<'\n';
	});
}

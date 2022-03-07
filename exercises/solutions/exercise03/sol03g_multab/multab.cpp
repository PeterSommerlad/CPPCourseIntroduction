#include <algorithm>


#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>



int main() {
	auto const limit = 20;
	std::vector<int> v(limit);
	std::iota(begin(v),end(v),1);
	std::for_each(cbegin(v),cend(v),
			[&v](int row){
				std::ostream_iterator<int> out{std::cout," \t"};
				transform(cbegin(v),cend(v),out,[row](int col){return row*col;});
				std::cout <<'\n';
	});
}

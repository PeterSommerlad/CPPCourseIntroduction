#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>
struct Accumulator {
  size_t count{0};
  double accumulatedValue{0.0};
  void operator()(double value) & {
    count++;
    accumulatedValue += value;
  }
  auto average() const {
    if (count > 0u)
      return accumulatedValue/count;
    return 0.0; // don't crash
  }
};
int main(){
  std::vector v{0.5,1.5,2.5,3.5,4.5,6.5};
  auto average {std::for_each(begin(v),end(v),
                Accumulator{}).average()};
  std::cout << "the average of\n";
  std::copy(begin(v),end(v),std::ostream_iterator<double>(std::cout,", "));
  std::cout << "\nis: " << average <<'\n';

  transform(begin(v),end(v),begin(v),[](auto x){ return -x;});
  std::copy(begin(v),end(v),std::ostream_iterator<double>(std::cout,", "));
  transform(begin(v),end(v),begin(v),std::negate{}); 
  std::cout <<'\n';
  std::copy(begin(v),end(v),std::ostream_iterator<double>(std::cout,", "));
  sort(begin(v),end(v),std::greater{});
  std::cout <<'\n';
  std::copy(begin(v),end(v),std::ostream_iterator<double>(std::cout,", "));

}
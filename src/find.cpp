#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <sstream>


void find42(std::istream &in) {
    using initer=std::istream_iterator<int>;
    std::vector<int> v{initer{in},initer{}};
    auto found=find(cbegin(v),cend(v),42);
    if (found != cend(v)){
        std::cout << "found value " << *found << "\n";
    } else {
        std::cout << "nothing found\n";
    }
}


void findOdd(std::vector<int> const &v) {
    auto odd=[](int x){ return x % 2;};
    auto found=find_if(cbegin(v),cend(v),odd);
    if (found != cend(v))
        std::cout << "found odd value " << *found << "\n";
    found = find_if_not(found,cend(v),odd);
    if (found != cend(v))
        std::cout << "found even value " << *found << "\n";
}



int main(){
    std::string input{"40 41 42 43"};
    std::istringstream is{input};
    find42(is);
    is.clear();
    is.seekg(0);
    using initer=std::istream_iterator<int>;
    findOdd(std::vector<int>{initer{is},initer{}});

}


#include <vector>

int main(){
  std::vector<int> v{};
  std::vector vv{v}; // copy
  if (v == vv){
    v.clear();
  }
}
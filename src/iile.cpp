#include <string>
#include <iostream>

void sayIfItIsEven(std::ostream & out, int number){
  std::string const eventext { 
    [](int number){
       if (number % 2 == 0) 
         return "even"; 
       else 
         return "odd";
     }(number) // invoke!
   };
  out << number << " is " << eventext << '\n';
}

int main(){
  sayIfItIsEven(std::cout,42);
  sayIfItIsEven(std::cout,1);
}
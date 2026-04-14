namespace calendar {
enum weekday : int { Mon, Tue, Wed, Thu, Fri, Sat, Sun };
weekday operator++(weekday &aday){
  int day = (aday+1)%(Sun+1);
  aday = static_cast<weekday>(day);
  return aday;
}


void demo(){
  int i=Mon;
  weekday aday{Tue};
  while(++aday != Mon);
  aday = static_cast<weekday>(42);
}




weekday operator++(weekday &aday,int){
  weekday ret{aday};
  if(aday == Sun) aday=Mon;
  else aday=static_cast<weekday>(1+aday);
  return ret;
}
}


namespace dummy{
enum Months {
  jan=1, feb, mar, apr, may, jun,
  jul, aug, sep, oct, nov, dec
};
//void dec(){} // compile error, conflicts
}




enum class month {
  jan=1, feb, mar, apr, may, jun,
  jul, aug, sep, oct, nov, dec
  , january=jan, february, march, april,
  june=jun, july, august, september, october,
  november, december
};
void dec(){} // no conflict with months::dec
static_assert(month::mar==month::march,"enumeration should continue");

enum class launch_policy : unsigned char {
  sync=1, async=2, gpu=4, process=8, none=0
};







#include <array>
#include <iostream>
int main(){
  using std::cout;
  using namespace calendar;
  weekday aday{Sat};
  if (++aday != Sun) cout << 1;
  if (aday++ != Sun) cout << 2;
  if (aday != Mon) cout << 3;
  month amonth{month::aug};
}








namespace demo_visibility_1 {
namespace calendar {
enum weekday {
  Mon, Tue, Wed, Thu, Fri, Sat, Sun
};
//Enumerators are visible here
}
bool is_weekend(calendar::weekday day) {
  return day == calendar::Sat || 
         day == calendar::Sun;
}
}








namespace demo_visibility_2 {
namespace calendar {
enum class weekday {
  Mon, Tue, Wed, Thu, Fri, Sat, Sun
};
}
bool is_weekend(calendar::weekday day) {
  return day == calendar::weekday::Sat || 
         day == calendar::weekday::Sun;
}
}
namespace calendar {
std::ostream& operator<<(std::ostream &out, weekday day){
  constexpr std::array names {"Mon","Tue","Wed","Thu","Fri","Sat","Sun"};
  return out << names.at(day);
}
}

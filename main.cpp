// add your code as appropriate 
#include <iostream>
#include "reservoir.h"
#include "reverseorder.h"

int main()
{
  //Test cases for Task A
  std::cout << "---Test Cases for Task A--- \n";
  std::string date1 = "05/20/2018";
  std::cout << "Date: " << date1 << "\n";
  std::cout << "East basin storage: " << get_east_storage(date1) << " billion gallons \n";


  //Test cases for Task B
  std::cout << "---Test Cases for Task B--- \n";
  std::cout << "Minimum storage in East basin: " << get_min_east() << " billion gallons \n";
  std::cout << "Maxmum storage in East basin: " << get_max_east() << " billion gallons \n";


  //Test cases for Task C
  std::cout << "---Test Cases for Task C--- \n";
  std::cout << "09/13/2018 " << compare_basins("09/13/2018") << "\n";
  std::cout << "011/03/2018 " << compare_basins("11/03/2018") << "\n";

  //Test cases for Task D
  std::cout << "---Test Cases for Task D #1--- \n";
  reverse_order("01/17/2018", "01/20/2018");

  std::cout << "---Test Cases for Task D #2--- \n";
  reverse_order("05/30/2018", "06/02/2018");

  return 0;
}

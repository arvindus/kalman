#include "math_lib.hpp" 
using namespace std; 

int main(void) { 
  my_float a(1.77222);  
  my_float b(1.2);
  set_precisions(23,1,2,23,4,5);
  my_float c1;
  c1 = a / 3;
  cout << "c1 = " << c1 << "\n";
  
  set_precisions(1,1,2,3,4,5);
  my_float c2;
  c2 = a / 3;
  cout << "c2 = " << c2 << "\n";
  
  cout << "Relative error = " << (c1.getVal() - c2.getVal())*100/c1.getVal() << "\n"; 

  cout << "main completed\n"; 
  return 0; 
}
#include "math_lib.hpp" 
using namespace std; 
int main(void) { 
  math_lib temp1 (23,2,3,4,5,6); 
  math_lib temp2(19,2,3,4,5,6); 
  float a = 1.77222; 
  float b = 1.61223; 
  float c1 = temp1.add(a,b); 
  float c2 = temp2.add(a,b); 
  cout << "Input = " << a << " and output = " << b << "\n";
  cout << "c1 = " << c1 << "\n"; 
  cout << "c2 = " << c2 << "\n"; 
  cout << "Relative error = " << ((c1 - c2) * 100)/c1 << "\n"; 
  cout << "main completed\n"; 
  return 0; 
}
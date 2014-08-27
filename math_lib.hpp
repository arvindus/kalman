#include <iomanip> 
#include <iostream> 
#include <cmath> 
#include <cstdlib> 

#define ADD_FULL_PREC 23 
#define SUB_FULL_PREC 23 
#define MUL_FULL_PREC 23 
#define DIV_FULL_PREC 23 
#define SQRT_FULL_PREC 23 
#define ATAN_FULL_PREC 23 

#define ASSERT(cond) if (cond) { cout << "Error in " << __FILE__ << " " << __func__ << " " << __LINE__ << "\n"; exit(1); } 
class math_lib 
{ 
  int add_prec;
  int sub_prec;
  int mul_prec;
  int div_prec;
  int sqrt_prec;
  int atan_prec; 
public: 
  math_lib(int add_p = ADD_FULL_PREC, int sub_p = SUB_FULL_PREC, int mul_p = MUL_FULL_PREC, int div_p = DIV_FULL_PREC, int sqrt_p = SQRT_FULL_PREC, int atan_p = ATAN_FULL_PREC);
  float add(float a, float b);
  float sub(float a, float b);
  float mul(float a, float b);
  float div(float a, float b);
  float squareroot(float a);
  float arctangent(float a);
};

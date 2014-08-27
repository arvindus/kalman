#include "math_lib.hpp" 

using namespace std;

typedef union { 
  float f;
  struct {
    unsigned int mantissa : 23; 
	unsigned int exponent : 8; 
	unsigned int sign : 1; 
  }	parts;
} float_cast;

static float change_precision_from_32_bits(float a, int prec);

math_lib::math_lib(int add_p, int sub_p, int mul_p, int div_p, int sqrt_p, int atan_p) {
  cout << "math_lib constructor called with:\nadd_p = " << add_p << "\n";
  cout << "sub_p = " << sub_p << "\n";
  cout << "mul_p = " << mul_p << "\n";
  cout << "div_p = " << div_p << "\n";
  cout << "sqrt_p = " << sqrt_p << "\n";
  cout << "atan_p = " << atan_p << "\n";
  add_prec = add_p;
  sub_prec = sub_p;
  mul_prec = mul_p;
  div_prec = div_p;
  sqrt_prec = sqrt_p; 
  atan_prec = atan_p;
  return;
}

static float change_precision_from_32_bits(float a, int prec) { 
  float c;
  float_cast c1;
  c1.f = a;
  ASSERT(prec > 23); 
  cout << "Before c1.f = " << c1.f << " n";
  unsigned int two_pow_23_minus_1 = 0x7FFFFF; 
  unsigned int two_pow_23_minus_prec_minus_1 = pow(2,23-prec) - 1;
  unsigned int mask = two_pow_23_minus_1 - two_pow_23_minus_prec_minus_1;
  cout << "mask = " << hex << mask << "\n";
  c1.parts.mantissa = c1.parts.mantissa & mask;
  cout << "After c1.f " << c1.f << "\n";
  return c1.f; 
} 

float math_lib::add(float a, float b) { 
  return(change_precision_from_32_bits(a,add_prec) + change_precision_from_32_bits(b,add_prec)); 
} 
float math_lib::sub(float a, float b) { 
  return(change_precision_from_32_bits(a,sub_prec) - change_precision_from_32_bits(b,sub_prec));
} 

float math_lib::mul(float a, float b) { 
  return(change_precision_from_32_bits(a,mul_prec) * change_precision_from_32_bits( b ,mul_prec)); 
} 
float math_lib::div(float a, float b) { 
  return(change_precision_from_32_bits(a,div_prec)/change_precision_from_32_bits(b,div_prec)); 
} 
float math_lib::squareroot(float a) { 
  return(sqrt(change_precision_from_32_bits(a,sqrt_prec))); 
} 
float math_lib::arctangent(float a) { 
  return(atan(change_precision_from_32_bits(a,atan_prec))); 
} 


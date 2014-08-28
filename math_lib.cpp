#include "math_lib.hpp" 

using namespace std;

static int add_prec = ADD_FULL_PREC;
static int sub_prec = SUB_FULL_PREC;
static int mul_prec = MUL_FULL_PREC;
static int div_prec = DIV_FULL_PREC;
static int sqrt_prec = SQRT_FULL_PREC;
static int atan_prec = ATAN_FULL_PREC;

typedef union { 
  float f;
  struct {
    unsigned int mantissa : 23; 
	unsigned int exponent : 8; 
	unsigned int sign : 1; 
  }	parts;
} float_cast;

void set_precisions(int add_p, int sub_p, int mul_p, int div_p, int sqrt_p, int atan_p) {
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
  //cout << "Before c1.f = " << c1.f << " n";
  unsigned int two_pow_23_minus_1 = 0x7FFFFF; 
  unsigned int two_pow_23_minus_prec_minus_1 = (1 << (23-prec)) - 1;
  unsigned int mask = two_pow_23_minus_1 - two_pow_23_minus_prec_minus_1;
  //cout << "mask = " << hex << mask << "\n";
  c1.parts.mantissa = c1.parts.mantissa & mask;
  //cout << "After c1.f " << c1.f << "\n";
  return c1.f; 
} 

static float add(float a, float b) { 
  return(change_precision_from_32_bits(a,add_prec) + change_precision_from_32_bits(b,add_prec)); 
} 

static float sub(float a, float b) { 
  return(change_precision_from_32_bits(a,sub_prec) - change_precision_from_32_bits(b,sub_prec));
} 

static float mul(float a, float b) { 
  return(change_precision_from_32_bits(a,mul_prec) * change_precision_from_32_bits( b ,mul_prec)); 
} 

static float div(float a, float b) { 
  return(change_precision_from_32_bits(a,div_prec)/change_precision_from_32_bits(b,div_prec)); 
} 

static float squareroot(float a) { 
  return(sqrt(change_precision_from_32_bits(a,sqrt_prec))); 
} 

static float arctangent(float a) { 
  return(atan(change_precision_from_32_bits(a,atan_prec))); 
}

my_float my_float::operator+(const my_float &a)
{
  my_float res(*this);
  res = add(this->val, a.val);
  return res;
}

my_float my_float::operator-(const my_float &a)
{
  my_float res(*this);
  res = sub(this->val, a.val);
  return res;
}

my_float my_float::operator*(const my_float &a)
{
  my_float res(*this);
  res = mul(this->val, a.val);
  return res;
}

my_float my_float::operator/(const my_float &a)
{
  my_float res(*this);
  res = div(this->val, a.val);
  return res;
}

my_float my_float::operator-(void)
{
  my_float res(*this);
  res = sub(0.0, this->val);
  return res;
}

my_float my_float::operator+=(const my_float &a)
{
  this->val = add(this->val, a.val);
  return *this;
}

my_float my_float::operator-=(const my_float &a)
{
  this->val = sub(this->val, a.val);
  return *this;
}

my_float my_float::operator*=(const my_float &a)
{
  this->val = mul(this->val, a.val);
  return *this;
}

my_float my_float::operator/=(const my_float &a)
{
  this->val = div(this->val, a.val);
  return *this;
}

  



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

extern void set_precisions(int add_p, int sub_p, int mul_p, int div_p, int sqrt_p, int atan_p);

class my_float
{ 
  float val;
public: 
  my_float() 
  { 
    val = 0.0; 
  }
  my_float(float x) 
  { 
    val = x; 
  }
  my_float(double x) 
  { 
    val = (float)(x); 
  }
  
  my_float(const my_float &mf) 
  { 
    val = mf.val;
  }
  
  void set_precisions(int add_p = ADD_FULL_PREC, int sub_p = SUB_FULL_PREC, int mul_p = MUL_FULL_PREC, int div_p = DIV_FULL_PREC, int sqrt_p = SQRT_FULL_PREC, int atan_p = ATAN_FULL_PREC);
  
  my_float operator+(const my_float &a);
  my_float operator-(const my_float &a);
  my_float operator*(const my_float &a);
  my_float operator/(const my_float &a);
  my_float operator-(void);
  
  my_float operator=(const my_float &mf)
  {
    val = mf.val; 
  }
  
  my_float operator+=(const my_float &a);
  my_float operator-=(const my_float &a);
  my_float operator*=(const my_float &a);
  my_float operator/=(const my_float &a);
  
  my_float sqrt(const my_float &a);
  my_float atan
  
  bool operator==(const my_float &a)
  {
    if (val == a.val)
      return true;
    else
      return false;
  }
  
  friend std::ostream &operator<<(std::ostream &output, const my_float &a)
  {
    output << "val = " << a.val;
    return output;
  }
  
  friend std::istream &operator>>(std::istream &input, my_float &a)
  {
    input >> a.val;
    return input;
  }
  
  float getVal(void) { return val; }
};

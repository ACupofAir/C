#include "polynomial.h"
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  Polynomial F(3);
  F.terms[0].coef = 1;
  F.terms[0].exp = 0;
  F.terms[1].coef = 2;
  F.terms[1].exp = 1;
  F.terms[2].coef = 5;
  F.terms[2].exp = 4;

  cout<<"The sum when x is 5 is "<<F.get_sum_polynomial(5)<<endl;

  return 0;
}

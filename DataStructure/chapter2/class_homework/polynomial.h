#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <cmath>
#include <vector>
using namespace std;

class Term {
  public:
    float coef;
    int exp;
};

class Polynomial{
  public:
    float x;
    vector<Term> terms;
    int degree;

  public:
    float get_sum_polynomial(float x); 
    Polynomial(int degree) {
      this->terms.resize(degree);
    }
    
};

float Polynomial::get_sum_polynomial(float x) {
  float sum = 0; 
  for(unsigned int i = 0; i < this->terms.size(); i++) {
    sum += terms[i].coef*pow(x,terms[i].exp);
  }
  return sum;
}

#endif

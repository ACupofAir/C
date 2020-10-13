#include <iostream> 
#include "Person.h"

using namespace std;
int main(void) {
  Person<int>* wj = new Person<int>("wj", 18);
  wj->greet();
  delete wj;
  Person<double> gzy("gzy", 99.2);
  gzy.greet();
  return 0;
}

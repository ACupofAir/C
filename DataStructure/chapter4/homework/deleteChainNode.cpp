#include <iostream>
#include "chain.h"
using namespace std;

int main(void) {
  chain<int> myList;
  myList.insert(1);
  cout<<myList.head->data;
  return 0;              
}                        
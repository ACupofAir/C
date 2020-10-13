#include <iostream>
#include "rectangle.h"

using namespace std;

int main() {
  Rectangle<int> fisrt_rectangle(1,1,4,5);
  Rectangle<int> second_rectangle(2,1,4,4);
  if(second_rectangle>fisrt_rectangle) {
    cout<<"Second is bigger than first"<<endl;
  } else {
    cout<<"Second is smaller than first"<<endl;
  }
  return 0;
}

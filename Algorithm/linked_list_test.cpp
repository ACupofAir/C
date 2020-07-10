#include <iostream>

using namespace std;

int main(void) {
  int data[100];
  int right[100];

  cout<<"Cin to data: \n";
  for(int i=1; i<10; i++) {
    cin>>data[i];
    right[i] = i+1;
  }
  right[9] = 0;

  cout<<"The linked list stores :"<<endl;
  int temp = 1;
  while(temp != 0) {
    cout<<data[temp]<<" ";
    temp = right[temp];
  }
  cout<<"Input a new number: "<<endl;
  cin>>data[10];

  temp = 1; 
  while(temp != 0) {
    if(data[right[temp]] > data[10]) {
      right[10] = right[temp];
      right[temp] = 10;
      break;
    } 

    temp = right[temp];
  }

  cout<<"Now the linked list stores :"<<endl;
  temp = 1;
  while(temp != 0) {
    cout<<data[temp]<<" ";
    temp = right[temp];
  }
}

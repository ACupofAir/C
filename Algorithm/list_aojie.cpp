#include <iostream>
#include <list>
#include <cmath>
#include <algorithm>
using namespace std;

void print_list(list<int> ran_list) {
  list<int>::iterator i;
  for(i = ran_list.begin(); i != ran_list.end(); i++) {
    cout<<*i<<" ";
  }
  cout<<endl;
}

int main(void) {
  int size;
  cout<<"Input the size of list"<<endl;
  cin >> size;
  list<int> my_list(0);
  for(int i = 0; i < size/2; i++) {
    my_list.push_back(rand()%(size/2));
  }
  for(int i = size/2; i < size; i++) {
    my_list.push_back(0);
  }

  cout<<"The first list is :";
  print_list(my_list);

  cout<<"Input the zero position: "<<endl;
  int pos;
  cin>>pos;
  list<int>::iterator iter;
  iter = my_list.begin();
  for(int i = 0; i < pos; i++) iter++;
  my_list.insert(iter,0);
  cout<<"The added list is :";
  print_list(my_list);


  cout<<"Input the delete position: "<<endl;
  int pos_det;
  cin>>pos_det;
  iter = my_list.begin();
  for(int i = 0; i < pos_det; i++) iter++;
  my_list.erase(iter);
  cout<<"The deteled list is :";
  print_list(my_list);

  my_list.reverse();
  cout<<"The reversed list is :";
  print_list(my_list);
  return 0;
}

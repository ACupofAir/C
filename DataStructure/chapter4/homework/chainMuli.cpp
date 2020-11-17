#include <iostream>
#include <list>                  
using namespace std;               
                                                
int main(void) {                                
  int number;                                    
  cout<<"Input n for arrayList: ";               
  cin>>number;                                   
  int* numArr = new int[number];                 
  for(int i = 0; i < number; i++) {              
    numArr[i] = rand()%10;                       
  }                                              
                                                 
  for(int i = 0; i < number; i++) {              
    cout<<numArr[i]<<" ";                        
  }                                              
                                                 
  list<int> numList;                             
  for(int i = 0; i < number; i++) {              
    numList.push_back(numArr[i]);                
  }                                              
                                                 
  list<int>::iterator it_front = numList.begin();
  list<int>::iterator it_back = it_front;        
  for(int i = 0; i < 5; i++) {                   
    it_back++;                                   
  }                                              
  int sum = 0;                                   
  for(int i = 0; i < number-5; i++) {            
    sum += (*it_front)*(*it_back);               
    it_front++;                                  
    it_back++;                                   
  }                                              
                                                 
  cout<<"Sum = " <<sum<<endl;                    
}                                                
#include "MyStack.H"                   
using namespace std;                   
                                       
                                       
int main(void)                         
{                                      
  MyStack<char> stk1;                  
  MyStack<char> stk2;                     
  char num[11] = {0};                     
  cout<<"Put some nums in stack\n";       
  cin.get(num,11);                        
  for(int i = 0; i < 10; i++)             
  {                                       
    stk1.push(num[i]);                    
    stk2.push(num[i]);                    
  }                                       
  stk2.split_stk();                       
  MyStack<char> stk_add;                  
  char num_add[6] = {0};                  
  cout<<"Put the num you add to stk1: \n";
  for(int i = 0; i < 5; i++)             
  {                                      
    cin>> num_add[i];                    
    stk_add.push(num_add[i]);            
  }                                      
  stk1.add_stk(stk_add);                  
  cout<<"stk1 after added : "<<endl;                   
  stk1.print_stk();                       
  return 0;                               
}                                         
                                          
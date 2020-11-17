#include "chain.h"
                                                              
template <class T>                                             
void a(chain<T>& myChain, node<T>* &l, node<T>* &r, int n) {    
  for(int i = 0; i < n; i++) {                                 
    if(r->next) {                                              
      r = r->next;                                             
    } else {                                                   
      //Now r is the end; we need make l the end; and make r Null 
      l = r;                                                        
      r = NULL;                                                 
      break;                                                   
    }                                                               
  }                                                                 
}                                                                   
                                                            
template <class T>                                          
void b(chain<T>& myChain, node<T>* &l, node<T>* &r, int n) {
  //inversion the list firstly                           
  node<T>* pp = NULL;                                           
  node<T>* p = myChain.head;                                            
  node<T>* p_temp = myChain.head->next;                                       
  p->next = pp;
  while(p->data!=r->data) {                              
    pp = p;                                              
    p = p_temp;                                          
    p_temp = p->next;                                    
    p->next = pp ;                                       
  }                                                      
  a(myChain, r, l, n);                                   
}                                                        
                                                                    
int main(void) {                                                    
  chain<int> testChain;                                             
  testChain.add(1);                                                 
  testChain.add(2);                                                 
  testChain.add(3);                                                 
  testChain.add(4);                                                 
  testChain.add(5);                                                 
  testChain.add(6);                                                 
  testChain.add(7);                                                 
  testChain.add(8);                                                    
  testChain.add(9);                                                    
                                                                       
  cout<<"Test a: \n";                                                  
  //l is the second node                                               
  node<int>* l = testChain.head->next;                                   
  //r is the third node                                                  
  node<int>* r = l->next;                                                
  a(testChain, l, r, 5);                                                 
  cout<<"l points to " <<l->data<<endl;                                  
  cout<<"r points to " <<r->data<<endl;                                  
  // cout<<"r is " <<r<<endl;                                               
                                                                         
  cout<<"Test b: \n";                                                    
  //l is the eighth node                                                  
  node<int>* l_b = testChain.head->next->next->next->next->next->next->next;                                 
  //r is the ninth node                                                  
  node<int>* r_b = l_b->next;                                                
  b(testChain, l_b, r_b, 5);                                                
  cout<<"l_b points to " <<l_b->data<<endl;                                  
  // cout<<"l_b is " <<l_b<<endl;                                               
  cout<<"r_b points to " <<r_b->data<<endl;                               
  return 0;                                                              
}                                                                        
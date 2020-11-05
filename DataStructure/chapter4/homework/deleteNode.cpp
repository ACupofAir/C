#include <iostream>
#include <list>                   
#include "deleteNode.h"
using namespace std;              
template <typename T>             
std::ostream &operator<<(std::ostream &s, const std::list<T> &v)
{                                      
    // s.put('[');                        
    s<<"[";                           
    char comma[3] = {'\0', ' ', '\0'}; 
    for (const auto& e : v) {          
        s << comma << e;               
        comma[0] = ',';                
    }                                  
    return s << ']';                   
}                                      
int main(void) {                       
  list<int> test_list {2,4,6,7,3};     
  list<int>::iterator it = test_list.begin();
  it++;                
  cout<<*it;                  
  return 0;                            
}                                      
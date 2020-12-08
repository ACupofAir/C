#ifndef SET_H
#define SET_H                                                                   
class Sets                                                                      
{                                                                               
public:                                                                         
  Sets(int numOfElements);                                                      
  void fill(int *begin, int *end, int value);                                   
  void SimpleUnion(int i, int j);                                                       
  int SimpleFind(int i);                                                                
  void WeightdUnion(int i, int j);                                                      
  int CollapsingFind(int i);                                                            
                                                                                        
private:                                                                                
  int *parent;                                                                          
  int n;                                                                                
};                                                                                      
                                                                                        
#endif                                                                                  
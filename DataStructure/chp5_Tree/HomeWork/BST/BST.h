#ifndef BST_H
#define BST_H                                   
#include <utility>                              
#include "Tree.h"                               
#include <iostream>                             
using namespace std;                            
                                                
template <class K, class E>                     
class BST: public Tree<pair<K, E>> {            
public:                                          
  BST(){                                         
    // cout<<"Init Sucessfully"<<endl;              
  };                                             
  void Insert(const pair<K,E>& thePair);         
                                                 
private:                                         
                                                 
};                                               
                                                 
template<class K, class E>                       
void BST<K,E>::Insert(const pair<K,E>& thePair)  
{                                                
  TreeNode<pair<K,E>>* p = this->root;           
  TreeNode<pair<K,E>>* pp = 0;                   
  while (p)                                      
  {                                              
    pp = p;                                      
    if(thePair.first<p->data.first)              
    {                                            
      p = p->leftChild;                          
    }                                            
    else if(thePair.second>p->data.first)        
    {                                            
      p = p->rightChild;                         
    }                                            
    else                                         
    {                                            
      p->data.second = thePair.second;           
      return;                                    
    }                                            
  }                                              
                                                 
  p = new TreeNode<pair<K,E>>(thePair);          
  if(this->root)                                 
  {                                              
    if(thePair.first<pp->data.first)             
    {                                            
      pp->leftChild = p;                         
    }                                            
    else                                         
    {                                               
      pp->rightChild = p;                           
    }                                               
  }                                                 
  else                                              
  {                                                 
    this->root = p;                                 
  }                                                 
                                                    
}                                                   
#endif                                              
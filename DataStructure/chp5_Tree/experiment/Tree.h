#ifndef TREE_H
#define TREE_H                
#include <iostream>
using namespace std;   
                               
                               
template <class T> class Tree; 
                               
template <class T>             
class TreeNode                 
{                              
  friend class Tree<T>;        
  public:               
    TreeNode(T data) {  
      this->data = data;
    }                   
  public:                     
    T data;                    
    TreeNode<T> *leftChild;          
    TreeNode<T> *rightChild;         
};                                   
                                     
template <class T>                   
class Tree                                    
{                                             
  public:                                     
  //operations                                
    void Inorder();                           
    void Inorder(TreeNode<T>*);               
                                              
                                              
  // private:                                    
    TreeNode<T> *root;                        
                                              
};                                            
                                              
template <class T>                            
void Tree<T>::Inorder(){                      
  Inorder(root);                              
};                                            
                                              
template <class T>                            
void Tree<T>::Inorder(TreeNode<T> *currentNode){
  if(currentNode) {                           
    Inorder(currentNode->leftChild);          
    cout<<currentNode->data<<"->";            
    Inorder(currentNode->rightChild);         
  }                                           
};                                            
                                              
#endif                                        
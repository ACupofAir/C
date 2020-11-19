#ifndef TREE_H
#define TREE_H                
#include <iostream>           
#include <queue>
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
    TreeNode<T> *root;                        
  //operations                                
    void Inorder();                           
    void Inorder(TreeNode<T>*);               
    void Preorder();                         
    void Preorder(TreeNode<T>*);             
    void Postorder();                         
    void Postorder(TreeNode<T>*);             
    void LevelOrder();
};                                            
                                              
template <class T>                            
void Tree<T>::Inorder(){                      
  Inorder(root);                              
}                                            
                                                     
template <class T>                                   
void Tree<T>::Inorder(TreeNode<T> *currentNode){     
  if(currentNode) {                                  
    Inorder(currentNode->leftChild);                 
    cout<<currentNode->data<<"->";                   
    Inorder(currentNode->rightChild);                                
  }                                                                  
}                                                                    
                                                                     
template <class T>                                                   
void Tree<T>::Preorder() {                                           
  Preorder(root);                                                    
}                                                                    
                                                                     
template <class T>                                                   
void Tree<T>::Preorder(TreeNode<T>* currentNode) {                   
  if(currentNode) {                                                  
    cout<<currentNode->data<<"->";                                   
    Preorder(currentNode->leftChild);                                
    Preorder(currentNode->rightChild);                               
  }                                                                  
}                                                                    
                                                                     
template <class T>                                                   
void Tree<T>::Postorder() {                                           
  Postorder(root);                                                    
}                                                                    
                                                                     
template <class T>                                                   
void Tree<T>::Postorder(TreeNode<T>* currentNode) {                   
  if(currentNode) {                                                  
    Postorder(currentNode->leftChild);                                
    Postorder(currentNode->rightChild);                               
    cout<<currentNode->data<<"->";                                   
  }                                                                  
}                                                                    
                                                              
template <class T>                                                   
void Tree<T>::LevelOrder() {                                  
  queue<TreeNode<T>*> q;                                      
  TreeNode<T>* currentNode = root;                            
  while(currentNode) {                                        
    cout<<currentNode->data<<"->";                                  
    if(currentNode->leftChild) q.push(currentNode->leftChild);
    if(currentNode->rightChild) q.push(currentNode->rightChild);
    if (q.empty())         
    {                      
      return;              
    }                      
    else                   
    {                      
      currentNode = q.front();
      q.pop();             
    }                      
  }                                                           
}                                                             
#endif                                                               
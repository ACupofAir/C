#ifndef TREE_H
#define TREE_H                                                                          
#include <iostream>                                                                     
#include <queue>                                                                        
#include <vector>     
#include <cmath>
using namespace std;                                                                    
                                                                                        
                                                                                        
template <class T> class Tree;
                      
template <class T>    
class TreeNode        
{                     
  friend class Tree<T>;
                      
public:               
  TreeNode()          
  {                   
  }                   
  TreeNode(T data)    
  {                   
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
                                                                                        
  //Constructor:                                                    
  //default:                                                        
  Tree<T>()                                                             
  {                                                                     
  }                                                                     
                                                                        
  Tree<T>(vector<T> &nodeVector) {                                      
    TreeNode<T>* nodeArr = new TreeNode<T>[nodeVector.size()+1];          
    for(int i = 0; i < nodeVector.size(); i++) {                        
      nodeArr[i+1].data = nodeVector[i];                                
    }                                                                   
    this->root = nodeArr+1;                                        
    int i=1;                                                       
    for(; i < pow(2, floor(log(nodeVector.size()/log(2))));i++)    
    {                                                              
     nodeArr[i].leftChild=nodeArr+2*i;                                 
     nodeArr[i].rightChild=nodeArr+2*i+1;                              
    }                                                                  
    for(;i<=nodeVector.size();i++)                                     
    {                                                                  
      nodeArr[i].leftChild=0;                                          
      nodeArr[i].rightChild=0;                                         
    }                                                                  
  }                                                                    
                                                                       
                                                                        
  //operations                                                          
  void Inorder();                                                       
  void Inorder(TreeNode<T> *);                                          
  void Preorder();                                                      
  void Preorder(TreeNode<T> *);                                         
  void Postorder();                                                     
  void Postorder(TreeNode<T> *);                                        
  void LevelOrder();                                                    
};                                                                      
                                                                        
template <class T>                                                      
void Tree<T>::Inorder()                                                 
{                                                                       
  Inorder(root);                                                        
}                                                                       
                                                                        
template <class T>                                                      
void Tree<T>::Inorder(TreeNode<T> *currentNode)                         
{                                                                       
  if (currentNode)                                                      
  {                                                                     
    Inorder(currentNode->leftChild);                                    
    cout << currentNode->data << "->";                                  
    Inorder(currentNode->rightChild);                                   
  }                                                                     
}                                                                       
                                                                        
template <class T>                                                      
void Tree<T>::Preorder()                                                
{                                                                       
  Preorder(root);                                                       
}                                                                       
                                                                        
template <class T>                                                      
void Tree<T>::Preorder(TreeNode<T> *currentNode)                        
{                                                                       
  if (currentNode)                                                      
  {                                                                     
    cout << currentNode->data << "->";                                  
    Preorder(currentNode->leftChild);                                   
    Preorder(currentNode->rightChild);                                  
  }                                                                     
}                                                                       
                                                                        
template <class T>                                                      
void Tree<T>::Postorder()                                               
{                                                                       
  Postorder(root);                                                      
}                                                                       
                                                                        
template <class T>                                                      
void Tree<T>::Postorder(TreeNode<T> *currentNode)                       
{                                                                       
  if (currentNode)                                                      
  {                                                                     
    Postorder(currentNode->leftChild);                                  
    Postorder(currentNode->rightChild);                                 
    cout << currentNode->data << "->";                                  
  }                                                                     
}                                                                       
                                                                        
template <class T>                                                      
void Tree<T>::LevelOrder()                                              
{                                                                       
  queue<TreeNode<T> *> q;                                               
  TreeNode<T> *currentNode = root;                                      
  while (currentNode)                                                   
  {                                                                     
    cout << currentNode->data << "->";                                  
    if (currentNode->leftChild)                                         
      q.push(currentNode->leftChild);                                   
    if (currentNode->rightChild)                                        
      q.push(currentNode->rightChild);                                  
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
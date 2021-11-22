#ifndef TREE_H
#define TREE_H                                                                          
#include <iostream>                                                                     
#include <algorithm>
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
  T data;                                                                              
  TreeNode<T> *leftChild;                                                              
  TreeNode<T> *rightChild;                                                             
                                                                                       
public:                                                                                
  TreeNode()                                                                           
  {                                                                                    
  }                                                                                    
  TreeNode(T data)                                                                     
  {                                                                                    
    this->data = data;                                                                 
    this->leftChild = nullptr; 
    this->rightChild = nullptr;
  }                                                                                    
  TreeNode(T data, TreeNode<T>* leftChild, TreeNode<T>* rightChild)                    
  {                                                                                    
    this->data = data;                                                                 
    this->leftChild = leftChild;                                                       
    this->rightChild = rightChild;                                                     
  }                                                                                    
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
    this->root = nullptr;      
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
                                                                                         
  //Copy constructor                                                                     
  Tree<T>(const Tree<T> &s) {                                                            
    this->root = Copy(s.root);                                                           
  }                                                                                      
                                                                                         
  //DestroyTree                                                                        
  ~Tree<T> () {                                                                        
    destroyTree(this->root);                                                           
  }                                                                                    
  void destroyTree(TreeNode<T>* cur) {                                                 
    // cout<<"Delete it\n";                                                               
    if(!cur) {                                                                         
      TreeNode<T>* temp_left = cur->leftChild;                                         
      TreeNode<T>* temp_right = cur->rightChild;                                        
      delete cur;                                                                      
      if(!temp_left) {                                                                 
        destroyTree(temp_left);                                                        
      }                                                                                
      if (!temp_right)                                                                 
      {                                                                                
        destroyTree(temp_right);                                                       
      }                                                                                
    }                                                                                   
  }                                                                                     
                                                                                         
  //operations                                                                           
  TreeNode<T>* Copy(TreeNode<T>* origNode);                                              
  void Inorder();                                                                        
  void Inorder(TreeNode<T> *);                                                           
  void Preorder();                                                                       
  void Preorder(TreeNode<T> *);                                                          
  void Postorder();                                                                      
  void Postorder(TreeNode<T> *);                                                         
  void LevelOrder();                                                                     
  int getHeight(TreeNode<T> *);  
  bool isEmpty() {                                                                     
    return !this->root;                                                                
  }                                                                                    
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
                                                                                                
template <class T>                                                                              
TreeNode<T>* Tree<T>::Copy(TreeNode<T> *origNode) {                                                
  if(!origNode) return 0;                                                                          
  return new TreeNode<T>(origNode->data, Copy(origNode->leftChild), Copy(origNode->rightChild));   
}                                                                                                  
                                                                                                   
template <class T>                                                                                 
int Tree<T>::getHeight(TreeNode<T>* rootNode)                                                          
{                                                                                                  
  return rootNode == NULL ? 0 : max(getHeight(rootNode -> leftChild), getHeight(rootNode -> rightChild)) + 1;
}                                                                                                  
                                                                          
#endif                                                                                             

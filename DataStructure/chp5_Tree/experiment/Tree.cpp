#include "Tree.h"
                                  
int main(void) {                  
  Tree<int> test_tree;            
  TreeNode<int> a(1);              
  TreeNode<int> b(2);              
  TreeNode<int> c(3);              
  TreeNode<int> d(4);              
  TreeNode<int> e(5);              
  TreeNode<int> f(6);              
  TreeNode<int> g(7);              
  test_tree.root = &a;             
  a.leftChild = &b;                
  a.rightChild = &c;               
  b.leftChild = &d;                
  b.rightChild = &e;               
  c.leftChild = &f;                
  c.rightChild = &g;               
  d.leftChild = NULL;              
  d.rightChild = NULL;             
  e.leftChild = NULL;               
  e.rightChild = NULL;              
  f.leftChild = NULL;               
  f.rightChild = NULL;              
  g.leftChild = NULL;               
  g.rightChild = NULL;              
  cout<<"Inorder: ";                
  test_tree.Inorder();              
  cout<<"\nPreorder:";              
  test_tree.Preorder();             
  cout<<"\nPostorder:";             
  test_tree.Postorder();            
  cout<<"\nLevelorder:";             
  test_tree.LevelOrder();            
  return 0;                         
}                                   
                                    
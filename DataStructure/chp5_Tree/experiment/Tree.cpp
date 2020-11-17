#include "Tree.h"
                                 
int main(void) {                 
  Tree<int> test_tree;            
  TreeNode<int> a(1);             
  TreeNode<int> b(2);             
  TreeNode<int> c(3);             
  TreeNode<int> d(4);             
  test_tree.root = &a;            
  test_tree.root->leftChild = &b; 
  test_tree.root->rightChild = &c;
  c.leftChild = &d;               
  test_tree.Inorder();            
  return 0;                       
}                                 
                                  
#include "Tree.h"
                                               
int main(void) {                                   
  vector<int> conTree{ 1, 2, 3, 4, 5, 6, 7};       
  Tree<int> test_tree(conTree);                
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
                                                   
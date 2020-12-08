#include "Tree.h"
                                                   
int main(void) {                                   
  vector<int> conTree{ 1, 2, 3, 4, 5, 6, 7};       
  Tree<int> test_tree(conTree);                    
  if (test_tree.isEmpty())                         
  {                                                
    cout << "Empty\n";                             
  }                                                
  else                                             
  {                                                
    cout << "It's not empty\n";                    
  }                                                
  cout<<"Inorder: ";                               
  test_tree.Inorder();                             
  cout<<"\nPreorder:";                             
  test_tree.Preorder();                            
  cout<<"\nPostorder:";                            
  test_tree.Postorder();                           
  cout<<"\nLevelorder:";                           
  test_tree.LevelOrder();                          
  Tree<int> copy_tree(test_tree);                  
  cout<<"\nCopyTree:";                             
  copy_tree.LevelOrder();                          
  return 0;                                        
}                                                  
                                                   
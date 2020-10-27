#include <iostream>
#include <stack>          
using namespace std;           
                               
int maze[14][17] = {           
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1},
    {1, 1, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1},
    {1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1}, 
    {1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 1}, 
    {1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1},       
    {1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1},       
    {1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1},       
    {1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1},       
    {1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1},       
    {1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1},        
    {1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1},        
    {1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1},                    
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};                   
                                                                            
class Pos                                                                   
{                                                                           
  public:                                                                   
    int x;                                                                  
    int y;                                                                  
};                                                                          
                                                                            
class MyStack                                                               
{                                                                           
  public:                                                                    
    Pos arr[180];                                                            
    int index;                                                               
    MyStack()                                                                
    {                                                                        
      this->index = 0;                                                       
    }                                                                        
};                                                                           
                                                                             
                                                                             
MyStack foot_path;                                                                    
void dfs_maze(Pos &cur)                                                      
{                                                                            
  // cout<<"("<<cur.x<<","<<cur.y<<")"<<"\t";                                   
  maze[cur.x][cur.y] = 1;                                                    
  if (cur.x == 12 && cur.y == 15)                                            
  {                                                                          
    cout << "Path: " << endl;                                                
    for (int i = 0; i < foot_path.index; i++)                                     
    {                                                                        
      cout<<"("<<foot_path.arr[i].x<<","<<foot_path.arr[i].y<<")"<<"\t\t";     
    }                                                                        
    return;                                                                  
  }                                                                          
  int next[8][2] = {                                                         
      {-1, -1},                                                              
      {-1, 0},                                                               
      {-1, +1},                                                              
      {0, +1},                                                               
      {+1, +1},                                                              
      {+1, 0},                                                               
      {+1, -1},                                                              
      {0, -1}};                                                              
  int tx, ty;                                                                
  for (int k = 0; k < 8; k++)                                                
  {                                                                          
    tx = cur.x + next[k][0];                                                 
    ty = cur.y + next[k][1];                                                 
    if (maze[tx][ty] == 0)                                                   
    {                                                                        
      Pos next_pos;                                                          
      next_pos.x = tx;                                                       
      next_pos.y = ty;                                                       
      foot_path.arr[foot_path.index] = next_pos;                                  
      foot_path.index++;                                                          
      dfs_maze(next_pos);                                                    
      foot_path.index--;                                                          
    }                                                                        
  }                                                                          
  return;                                                                    
}                                                                            
                                                                             
int main(void) {                                                             
  for(int i = 1; i <= 12; i++)                                               
  {                                                                          
    for(int j = 1; j <= 15; j++)                                             
    {                                                                        
      cout<<maze[i][j];                                                      
    }                                                                        
    cout<<endl;                                                              
  }                                                                          
  Pos init_position;                                                         
  init_position.x = 1;                                                       
  init_position.y = 1;                                                       
  dfs_maze(init_position);                                                   
                                                                             
  return 0;                                                                  
}                                                                            
#include <iostream>
#include <time.h> 
#include <stdlib.h>           
#include "Airpot.h"                                                                     
using namespace std;              
                                  
int main(void)                      
{                                                                                                      
  int will_fly_plane_num, will_land_plane_num;                                                         
  int my_time;                                                                                            
                                                                                                       
  //Airpot start work                                                                                  
  srand((int)time(0));                                                       
  for (my_time = 0; my_time < 10; my_time++)                                                                    
  {                                                                                                    
    //produce planes                                                                                   
    // will_fly_plane_num = rand() % 4;                                                                   
    will_fly_plane_num = 3;                                                                                            
    will_land_plane_num = rand() % 4;                                                                                  
    vector<Plane> fly_queue;                                                                                           
    for (int i = 0; i < will_fly_plane_num; i++)                                                                       
    {                                                                                                                  
      fly_queue.push_back(Plane(2 * i, 0));                                                                            
    }                                                                                                                  
    vector<Plane> land_queue;                                                                                                  
    for (int i = 0; i < will_land_plane_num; i++)                                                                              
    {                                                                                                                          
      land_queue.push_back(Plane(2 * i + 1, 1));                                                                               
    }                                                                                                                          
                                                                                                                               
    //Fly planes when my_time is odd; and land planes when it's even                                                              
    if (my_time % 2 == 0)                                                                                                         
    {                                                                                                                          
      cout << "Time: " << my_time << endl;                                                                             
      int land_mark = 0;                                                                                               
      //If there is someone must be land, make the third way to land it                                                        
      for (int i = 0; i < land_queue.size(); i++)                                                                              
      {                                                                                                                        
        if(land_queue[i].remained_time==0)                                                                                     
        {                                                                                                                      
          land_queue.erase(land_queue.begin()+i);                                                                              
          land_mark = 1;                                                                                                       
          break;                                                                                                               
        }                                                                                                                      
        //If none need land the third runway will fly a plane                                                                  
        if (land_mark == 0 && land_queue.size() > 0)                                                                           
        {                                                                                                                      
          fly_queue.erase(fly_queue.begin());                                                                                  
        }                                                                                                                       
      }                                                                                                                         
      if (land_queue.size() >= 2)                                                                                               
        land_queue.erase(land_queue.begin(), land_queue.begin() + 1);                                                           
    }                                                                                                                           
    else if (my_time % 2 == 1)                                                                                                    
    {                                                                                                                           
      cout << "Time: " << my_time << endl;                                                                                        
      int must_land_plane_num = 0;                                                                                              
      for (int i = 0; i < land_queue.size(); i++)                                                                               
      {                                                                                                                         
        if(land_queue[i].remained_time==0)                                                                                     
        {                                                                                                                       
          land_queue.erase(land_queue.begin()+i);                                                                               
          must_land_plane_num++;                                                                                                
        }                                                                                                                       
      }                                                                                                                         
      if (must_land_plane_num > 3)                                                                                              
        cout << "The airpot is boom!" << endl;                                                                                  
      else                                                                                                                      
      {                                                                                                                         
        for (int i = 0; i < (3 - must_land_plane_num && fly_queue.size() > (3-must_land_plane_num)); i++)                                
        {                                                                                                                       
          fly_queue.erase(fly_queue.begin());                                                                                   
        }                                                                                                                       
        cout << "There are " << must_land_plane_num << " planes must to be land" << endl;                                       
      }                                                                                                                         
    }                                                                                                                           
                                                                                                                                
    //Print info:                                                                                                               
    print_fly_plane_queue_info(fly_queue);                                                                                      
    print_land_plane_queue_info(land_queue);                                                                                    
  }                                                                                                                             
  return 0;                                                                                                                     
}                                                                                                                               
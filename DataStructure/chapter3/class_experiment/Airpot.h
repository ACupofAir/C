#ifndef AIRPOT_H
#define AIRPOT_H                     
#include <vector>                       
using namespace std;                                                                           
                                                                                               
class Plane{                                                                                   
  public:                                                                                      
    int id;                                                                                    
    int remained_time;                     
                                                                  
    Plane(int id, int is_land)                                    
    {                                                             
      this->id = id;                                                                                        
      if (is_land == 1)                                                                                     
        this->remained_time = rand() % 10;                                                                  
    }                                                                                                       
};                                                                                                          
                                                                                                            
void print_land_plane_queue_info(vector<Plane> plane_queue)                                                                  
{                                                                                                           
  if(plane_queue.size() == 0) cout<<"The land queue is empty"<<endl;                             
  cout<<"The land plane queue's info: "<<endl;                                                   
  int sum_remained_time = 0;                                                                     
  for(int i = 0; i < plane_queue.size(); i++)                                                               
  {                                                                                                         
    sum_remained_time += plane_queue[i].remained_time;                                           
    cout<<"Plane"<<plane_queue[i].id<<" has "<<plane_queue[i].remained_time<<" time to land"<<endl;          
  }                                                                                                         
  if(plane_queue.size() > 0)                                                                     
    cout << "The average time of remained is " << sum_remained_time / plane_queue.size() << endl;
}                                                                                                           
                                                                                                            
void print_fly_plane_queue_info(vector<Plane> plane_queue)                                                                  
{                                            
  cout << "The fly plane queue's info: " << endl;
  if (plane_queue.size() == 0)               
    cout << "The fly queue is empty" << endl;
  for(int i = 0; i < plane_queue.size(); i++)                                                               
  {                                                                                                         
    cout<<"Plane"<<plane_queue[i].id<<" ";                                                                  
  }                                                                                                         
  cout<<endl;                                                                                               
}                                                                                                           
                                                                                                            
// class Runway{                                                                                            
//   public:                                                                                                
//     vector<Plane> fly_queue;                                                                             
//     vector<Plane> land_queue;                                                                            
// };                                                                                                       
                                                                                                            
#endif                                                                                                      
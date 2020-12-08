#ifndef MAXHEAP_H
#define MAXHEAP_H            
#include <vector>            
using namespace std;         
                             
template <class T>           
class MaxHeap                
{                            
private:                     
  vector<T> heap;            
  int heapSize;               
  int capacity;               
                              
public:                        
  vector<T> getHeap()         
  {                           
    return this->heap;        
  }                           
                              
  int getheapSize()              
  {                           
    return this->heapSize;             
  }                           
                              
  void setheapSize(int heapSize)          
  {                           
    this->heapSize = heapSize;                  
  }                           
                              
  int getcapacity()              
  {                           
    return this->capacity;             
  }                           
                              
  void setcapacity(int capacity)         
  {                           
    this->capacity = capacity;                  
  }                           
                              
  MaxHeap();                  
  void Push(const T &e);      
};                            
                              
template <class T>            
MaxHeap<T>::MaxHeap()         
{                             
  this->heapSize = 0;         
  this->capacity = 2;         
  this->heap.resize(capacity);       
}                             
                              
template <class T>            
void MaxHeap<T>::Push(const T &e)
{                             
  if (heapSize == capacity-1)
  {                           
    capacity *= 2;            
    this->heap.resize(capacity);
  }                           
                              
  int currentNode = ++heapSize;
  while (currentNode != 1 && heap[currentNode / 2] < e)
  {                           
    heap[currentNode] = heap[currentNode / 2];
    currentNode /= 2;         
  }                           
  heap[currentNode] = e;      
}                             
                              
#endif                        
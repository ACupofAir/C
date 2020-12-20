#ifndef MINHEAP_H
#define MINHEAP_H
#include <vector>
using namespace std;

template <class T>
class MinHeap
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

  bool isEmpty()
  {
    return (this->heap.size() == 1);
  }

  MinHeap();
  void Push(const T &e);
  T Top();
  void Pop();
};

template <class T>
MinHeap<T>::MinHeap()
{
  this->heapSize = 0;
  this->capacity = 2;
  this->heap.resize(capacity);
}

template <class T>
void MinHeap<T>::Push(const T &e)
{
  if (heapSize == capacity - 1)
  {
    capacity *= 2;
    this->heap.resize(capacity);
  }

  int currentNode = ++heapSize;
  while (currentNode != 1 && heap[currentNode / 2] > e)
  {
    heap[currentNode] = heap[currentNode / 2];
    currentNode /= 2;
  }
  heap[currentNode] = e;
}

template <class T>
T MinHeap<T>::Top()
{
  if (this->isEmpty())
    throw "MinHeap is empty";
  return heap[1];
}

template <class T>
void MinHeap<T>::Pop()
{
  if (this->isEmpty())
    throw "MinHeap is empty";
  T lastE = heap[heapSize--];

  int currentNode = 1;
  int child = 2;
  while (child <= heapSize)
  {
    if (child < heapSize && heap[child] > heap[child + 1])
      child++;

    if (lastE <= heap[child])
      break;

    heap[currentNode] = heap[child];
    currentNode = child;
    child *= 2;
  }
  heap[currentNode] = lastE;
}

#endif
#ifndef EDGE_H
#define EDGE_H

#include <iostream>

using namespace std;

class Edge
{
private:
  int head;
  int tail;
  int weight;

public:
  Edge(){};
  Edge(const int& head, const int& tail, const int& weight)
  {
    this->head = head;
    this->tail = tail;
    this->weight = weight;
  }
  Edge(const int head, const int tail)
  {
    this->head = head;
    this->tail = tail;
    this->weight = 0;
  }

  int getHead() { return this->head; }
  int getTail() { return this->tail; }
  int getWeight() { return this->weight; }
  void setHead(int& head) {this->head = head;}
  void setTail(int& tail) {this->tail = tail;}
  bool operator<(const Edge &e) { return this->weight < e.weight; }
  bool operator>(const Edge &e) { return this->weight > e.weight; }
  bool operator>=(const Edge &e) { return this->weight >= e.weight; }
  bool operator<=(const Edge &e) { return this->weight <= e.weight; }
  bool operator==(const Edge &e) { return this->weight = e.weight; }
};

#endif
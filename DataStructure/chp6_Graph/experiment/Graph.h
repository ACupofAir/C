#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <iostream>
#include "Edge.h"

using namespace std;

class Graph
{
private:
  int eNum;
  int vNum;
  vector<Edge> edge;

public:
  Graph(int eNum, int vNum);
  void addEdge(Edge newEdge);
  void print();
  int getENum()
  {
    return this->eNum;
  }
  int getVNum()
  {
    return this->vNum;
  }
  vector<Edge> getEdge()
  {
    return this->edge;
  }
};

Graph::Graph(int eNum, int vNum)
{
  this->eNum = eNum;
  this->vNum = vNum;
  this->edge = vector<Edge>(eNum);
}

void Graph::print()
{
  for(int i = 0; i < this->edge.size(); i++)
  {
    cout<<"("<<this->edge[i].getHead()<<", "<<this->edge[i].getTail()<<", "<<this->edge[i].getWeight()<<")"<<endl;
  }
}

void Graph::addEdge(Edge newEdge)
{
  this->edge.push_back(newEdge);
}

#endif
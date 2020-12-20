#include <iostream>
#include <vector>

using namespace std;

class Edge
{
private:
  int head;
  int tail;
  int weight;

public:
  Edge(){};
  Edge(int head, int tail, int weight)
  {
    this->head = head;
    this->tail = tail;
    this->weight = weight;
  }
  int getHead()
  {
    return this->head;
  }
  int getTail()
  {
    return this->tail;
  }
  int getWeight()
  {
    return this->weight;
  }
};

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
};

class Set
{
private:
  int n;
  int *parent;

public:
  Set(int num);
  void WeightUnion(int i, int j);
  int CollapsingFind(int i);
};

Set::Set(int n)
{
  if (n < 2)
    throw "Must has at least two elements.";
  this->n = n;
  this->parent = new int[n];
  for (int i = 0; i < n; i++)
  {
    parent[i] = -1;
  }
}

void Set::WeightUnion(int i, int j)
{
  int temp = parent[i] + parent[j];
  if(parent[i] > parent[j])
  {
    parent[i] = parent[j];
    parent[j] = temp;
  }
  else
  {
    parent[j] = parent[i];
    parent[i] = temp;
  }
}

int Set::CollapsingFind(int i)
{
  int root;
  for(root = i; parent[root] >= 0; root = parent[root]);
  while(i != root)
  {
    int s = parent[i];
    parent[i] = root;
    i = s;
  }
  return i;
}

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

int main(void)
{
  Graph testGraph(0,0);
  vector<Edge> edges(9);
  edges[0] = Edge(0,1,28);
  edges[1] = Edge(1,2,16);
  edges[2] = Edge(2,3,12);
  edges[3] = Edge(3,4,22);
  edges[4] = Edge(4,5,25);
  edges[5] = Edge(5,0,10);
  edges[6] = Edge(3,6,18);
  edges[7] = Edge(4,6,24);
  edges[8] = Edge(1,6,14);
  for(int i = 0; i < edges.size(); i++)
  {
    testGraph.addEdge(edges[i]);
  }
  testGraph.print();
  return 0;
}
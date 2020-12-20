#include "Edge.h"
#include "Set.h"
#include "Graph.h"
#include "MinHeap.h"

using namespace std;

Graph Kruskal(Graph &graph)
{
  MinHeap<Edge> heapE;
  for(int i = 0; i < graph.getEdge().size(); i++)
  {
    heapE.Push(graph.getEdge()[i]);
  }
  Graph newGraph(graph.getENum(), graph.getVNum());
  // Set vertice(graph.getVNum());
  Set vertice(7);

  while(heapE.Top().getWeight()>0)
  {
    Edge minEdge = heapE.Top();
    heapE.Pop();
    int newHead = minEdge.getHead();
    int newTail = minEdge.getTail();
    int p1 = vertice.CollapsingFind(newHead);
    int p2 = vertice.CollapsingFind(newTail);
    if (p1 != p2)
    {
      vertice.WeightUnion(p1,p2);
      newGraph.addEdge(minEdge);
    }
  }
  return newGraph;
}

int main(void)
{
  Graph testGraph(0,0);
  vector<Edge> edges(9);
  // MinHeap<Edge> tempEdges;
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
    // tempEdges.Push(edges[i]);
  }

  Graph newGraph(0, 0);
  newGraph = Kruskal(testGraph);

  cout << "Old:\n";
  testGraph.print();
  cout<<"New:\n";
  newGraph.print();
  return 0;
}
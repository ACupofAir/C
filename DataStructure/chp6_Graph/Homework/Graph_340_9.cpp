#include <iostream>
#include <vector>
#include <list>
#include "Edge.h"

using namespace std;

int main(void)
{
  //Init edge and vertive's number
  int edgeNum;
  int verticeNum;
  printf("Input Edge's num:\n");
  scanf("%d", &edgeNum);
  printf("Input Vertice's num:\n");
  scanf("%d", &verticeNum);
  vector<Edge> graphEdges;
  vector<list<int>> adjacencyList(verticeNum);

  for (int i = 0; i < edgeNum; i++)
  {
    int tempHead, tempTail;
    printf("Input the edge's head and tail:\n");
    scanf("%d %d", &tempHead, &tempTail);
    graphEdges.push_back(Edge(tempHead, tempTail));
    adjacencyList[tempHead].push_back(tempTail);
    adjacencyList[tempTail].push_back(tempHead);
  }

  for(int i = 0; i < verticeNum; i++)
  {
    cout<<"adjacencyList["<<i<<"]"<<"->";
    while(!adjacencyList[i].empty())
    {
      cout<<adjacencyList[i].front();
      adjacencyList[i].pop_front();
      cout<<"->";
    }
    cout<<"null"<<endl;
  }
  cout<<adjacencyList.size();

  return 0;
}

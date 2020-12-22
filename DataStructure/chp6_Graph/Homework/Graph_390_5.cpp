#include <iostream>
#include <vector>
#include <list>
#include "Edge.h"

using namespace std;

void TopologicalOrder(vector<list<int>>& adjList)
{
  vector<int> count(adjList.size());
  for(int i = 0; i < adjList.size(); i++)
  {
    for (list<int>::iterator it = adjList[i].begin(); it != adjList[i].end(); it++)
    {
      count[*it]++;
    }
  }

  for (int j = 0; j < count.size(); j++)
  {
    for (int i = 0; i < count.size(); i++)
    {
      //Per is lived up, cout it and mark it -1
      if (count[i] == 0)
      {
        cout << i << "->";
        count[i] = -1;
        //Meanwhile, update the count depend on i
        for (list<int>::iterator it = adjList[i].begin(); it != adjList[i].end(); it++)
        {
          count[*it]--;
        }
        break;
      }
    }
  }
  cout << "end" << endl;
}

int main(void)
{
  //Init a graph
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
  }

  TopologicalOrder(adjacencyList);

  return 0;
}
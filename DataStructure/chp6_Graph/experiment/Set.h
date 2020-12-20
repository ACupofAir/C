#ifndef SET_H
#define SET_H
#include <vector>
using namespace std;

class Set
{
private:
  int n;
  vector<int> parent;

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
  this->parent.resize(n);
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
    parent[i] = j;
    parent[j] = temp;
  }
  else
  {
    parent[j] = i;
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

#endif
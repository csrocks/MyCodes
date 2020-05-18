#include<bits/stdc++.h>
using namespace std;
#define PIII pair<int, pair<int, int>> // {weight, {x,y}}

vector<int> id;

int root(int x){
  while(id[x] != x){
    id[x] = id[id[x]];
    x = id[x];
  }
  return x;
}

void union_(int x, int y){
  int X = root(x);
  int Y = root(y);
  id[X] = id[Y];
}

int kruskal(vector<PIII> graph){
  int mincost = 0;
  for(int i=0; i<graph.size(); i++){
    int x = graph[i].second.first;
    int y = graph[i].second.second;
    int cost = graph[i].first;

    if(root(x) != root(y)){
      mincost += cost;
      union_(x, y);
    }
  }
  return mincost;
}

int main(){
  vector<PIII> graph = { {4,{0,1}}, {1,{0,3}}, {3,{1,2}}, {2,{3,2}}, {2,{2,4}} };
  sort(graph.begin(), graph.end());
  for(int i=0; i<graph.size(); i++) id.push_back(i);
  cout << kruskal(graph);
}
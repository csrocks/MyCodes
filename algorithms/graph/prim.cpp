#include<bits/stdc++.h>
using namespace std;
#define PII pair<int, int>

int prim(vector<vector<PII>> graph){
  priority_queue<PII, vector<PII>, greater<PII>> Q;
  bool visited[graph.size()] = {false};
  int mincost = 0;
  Q.push({0,0});

  while(!Q.empty()){
    PII curr = Q.top(); Q.pop();
    int x = curr.second;
    if(visited[x]) continue;
    visited[x] = true;
    mincost += curr.first;

    for(int i=0; i<graph[x].size(); i++){
      int cost = graph[x][i].first;
      int y = graph[x][i].second;
      if(!visited[y]) Q.push({cost, y});
    }
  }
  return mincost;
}

int main(){
  vector<vector<PII>> graph = { {{4,1},{1,3}}, {{4,0},{3,2}}, {{3,1},{2,3},{2,4}}, {{1,0},{2,2}}, {{2,2}} }; // {weight, y}
  cout << prim(graph);
}
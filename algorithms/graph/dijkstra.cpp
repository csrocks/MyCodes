#include<bits/stdc++.h>
using namespace std;
#define PII pair<int, int>

void dijkstra(vector<vector<PII>> graph, vector<int> &dist){
  priority_queue<PII, vector<PII>, greater<PII>> Q;
  bool visited[graph.size()] = {false};
  Q.push({0,0});
  dist[0] = 0;
  
  while(!Q.empty()){
    PII curr = Q.top(); Q.pop();
    int x = curr.second;
    if(visited[x]) continue;
    visited[x] = true;
    int cost = curr.first;

    for(int i=0; i<graph[x].size(); i++){
      int cost = graph[x][i].first;
      int y = graph[x][i].second;
      if(dist[x] + cost < dist[y]){
        dist[y] = dist[x] + cost;
        Q.push({dist[y], y});
      }
    }
  }
}

int main(){
  vector<vector<PII>> graph = { {{4,1},{1,3},{1,2}}, {{4,0},{3,2}}, {{1,0},{3,1},{2,3},{2,4}}, {{1,0},{2,2}}, {{2,2}} }; // {weight, y}
  vector<int> dist(graph.size(), INT_MAX);
  dijkstra(graph, dist);
  for (int i: dist) cout << i << " ";
}
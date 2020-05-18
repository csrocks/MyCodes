#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> graph){
  queue<int> q;
  bool visited[graph.size()] = {false};
  q.push(0);
  visited[0] = true;
  while(!q.empty()){
    int curr = q.front(); q.pop();
    cout << curr << " ";
    for(int i=0; i<graph[curr].size(); i++){
      if(visited[graph[curr][i]]) continue;
      visited[graph[curr][i]] = true;
      q.push(graph[curr][i]);
    }
  }
}

int main(){
  vector<vector<int>> graph = {{1,3},{0,2},{1,3,4},{0,2},{2}};
  bfs(graph);
}
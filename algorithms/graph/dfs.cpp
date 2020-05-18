#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> graph){
  stack<int> s;
  bool visited[graph.size()] = {false};
  s.push(0);
  visited[0] = true;
  while(!s.empty()){
    int curr = s.top(); s.pop();
    cout << curr << " ";
    for(int i=0; i<graph[curr].size(); i++){
      if(visited[graph[curr][i]]) continue;
      visited[graph[curr][i]] = true;
      s.push(graph[curr][i]);
    }
  }
}

void dfs_rec(vector<vector<int>> graph, bool visited[], int root){
  if(visited[root]) return;
  visited[root] = true;
  for(int i=0; i<graph[root].size(); i++) dfs_rec(graph, visited, graph[root][i]);
  cout << root <<" ";
}
int main(){
  vector<vector<int>> graph = {{1,3},{0,2},{1,3,4},{0,2},{2}};
  dfs(graph);
  cout << endl;
  bool visited[graph.size()] = {false};
  dfs_rec(graph, visited, 0);
}
#include<bits/stdc++.h>
using namespace std;
stack<int> s;
void toposort_dfs(int x,int n,int adj[][5],int* visited){
    visited[x]=1;
    for(int i=0;i<n;i++){
    	if(adj[x][i]!=0 && visited[i]==0){
    		toposort_dfs(i,n,adj,visited);
    	}
    }
    s.push(x);
}
int main(){
    int i,j,k,n=5;

    int adj[5][5];
    for(i=0;i<n;i++) for(j=0;j<n;j++) cin>>adj[i][j];
    int t[n];
    int visited[n];
    for(i=0;i<n;i++) visited[i]=0;
    toposort_dfs(0,n,adj,visited);
    for(i=0;i<n;i++){
    	t[i]=s.top();
    	s.pop();
    }
    for(i=0;i<n;i++) cout<<t[i]<<" ";
}

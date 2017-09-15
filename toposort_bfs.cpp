#include<bits/stdc++.h>
using namespace std;
int* toposort_bfs(int n,int adj[][5],int* t){
    int i,j,k,x=0;
    int indegree[n];
    bool visited[n];
    for(i=0;i<n;i++){
        visited[i]=false;
        indegree[i]=0;
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(adj[i][j]!=0) indegree[j]++;
        }
    }
    queue <int> q;
    for(i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
            visited[i]=true;
        }
    }
    while(!q.empty()){
        k=q.front();
        cout<<k<<".";
        q.pop();
        t[x]=k;
        x++;
        for(j=0;j<n;j++){
            if(adj[k][j]!=0 && visited[j]==false){
                indegree[j]--;
                if(indegree[j]==0){
                    q.push(j);
                    visited[j]=true;
                }
            }
        }
    }
    return t;
}
int main(){
    int i,j,k,n=5;
    int adj[5][5];
    for(i=0;i<n;i++) for(j=0;j<n;j++) cin>>adj[i][j];
    int t[n];
    toposort_bfs(n,adj,t);
    for(i=0;i<n;i++) cout<<t[i]<<" ";
}

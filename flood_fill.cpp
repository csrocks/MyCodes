#include<bits/stdc++.h>
using namespace std;
int v[10][10],vis[10][10];
void df(n){
	int i,j,k;
	stack s;
	s.push(n);
	vis[s]=true;
	while(!s.empty()){
		k=s.top();
		s.pop();

		for(i=0;i<v[k].size();i++){
			if(vis(v[k][i])==false)
				push(v[k][i]);
			vis(v[k][i])=true;
		}
	}
}
bool dfs(int v[10][],int vis[10][],int i,int j,int n,int m){
    if(i>=n || j>=m) return false;
    if(i<0 || j<0) return false;
    if(vis[i][j]==true) return false;
    if(v[i][j]==0) return false;
    if(i==n-1 && j==m-1) return true;
    vis[i][j]=true;
    if(dfs(v,vis,i-1,j,n,m)) return true;
    if(dfs(v,vis,i+1,j,n,m)) return true;
    if(dfs(v,vis,i,j-1,n,m)) return true;
    if(dfs(v,vis,i,j+1,n,m)) return true;
    return false;
}
int main(){
	int i,j,k,m,n;
	cin>>n>>m;
	for(i=0;i<n;i++){
        for(j=0;j<m;j++) cin>>a[i][j];
	}
	if(dfs(v,vis,i,j,n,m)) cout<<"Yes";
	else cout<<"No";
}

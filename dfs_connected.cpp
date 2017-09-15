#include <bits/stdc++.h>
using namespace std;
void dfs(int s,vector<int>* v, bool* vis){
	vis[s]=true;
	int i;
	for(i=0;i<v[s].size();i++){
		if(vis[v[s][i]]==false){
			dfs(v[s][i],v,vis);
		}
	}
}
int main(){
	int i,j,k,n,e,c=0,x,y;
	cin>>n>>e;
	vector <int> v[n];
	bool vis[n];
	for(i=0;i<e;i++){
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(i=0;i<n;i++){
		vis[i]=false;
	}
	for(i=0;i<n;i++){
		if(vis[i]==false){
			dfs(i,v,vis);
			c++;
		}
	}
	cout<<c;
}

#include <bits/stdc++.h>
using namespace std;
int main(){
	int i,j,k,n;
	vector <int> v[10];
	int level[10];
	bool vis[10];
	void bfs(int s){
		queue <int> q;
		q.push(s);
		level[s]=0;
		vis[s]=true;
		while(!q.empty()){
			k=q.front();
			q.pop();
			for(i=0;i<v[k].size();i++){
				if(vis[v[k][i]]==false){
					level[v[k][i]]=level[k]+1;
					q.push(v[k][i]);
					vis[v[k][i]]=true;
				}
			}
		}
	}
}



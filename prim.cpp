#include<bits/stdc++.h>
using namespace std;

const int maxx=1e4+5;
typedef pair<int,int> P;
bool marked[maxx];
vector <P> adj[maxx];

int prim(int x){
    priority_queue <P,vector<P>,greater<P> > q;
    int minc=0,i,cost,y;
    P p;
    q.push(make_pair(0,x));
    while(!q.empty()){
    	//cout<<"y";
        p=q.top();
        q.pop();
        cost=p.first;
        x=p.second;
        //cout<<marked[x];
        if(marked[x]==true) continue;
        minc+=cost;
        marked[x]=true;
        for(i=0;i<adj[x].size();i++){
        	//cout<<"y";
            y=adj[x][i].second;
            if(marked[y]==false)
                q.push(adj[x][i]);
        }
    }
    //cout<<"y";
    return minc;
}
int main(){
    int i,j,k,x,y,w,nodes,edges;
    cin>>nodes>>edges;
    for(i=0;i<nodes;i++) marked[i]=false;
    for(i=0;i<edges;i++){
        cin>>x>>y>>w;
        adj[x].push_back(make_pair(w,y));
        adj[y].push_back(make_pair(w,x));
    }
    //cout<<"y";
    cout<<prim(1);
    //cout<<"y";
    return 0;
}

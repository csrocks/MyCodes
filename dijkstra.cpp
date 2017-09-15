#include<bits/stdc++.h>
using namespace std;
#define siz 100000+1
vector<pair<int,int>> v[siz];
int dist[siz];
bool vis[siz];

void dijkstra(){
    for(int i=0;i<siz;i++) dist[i]=2e5;
    memset(vis,false,sizeof vis);
    dist[0]=0;
    multiset<pair<int,int>> s;

    s.insert({0,0});
    while(!s.empty()){
        pair<int,int> p =*s.begin();
        s.erase(s.begin());

        int we=p.second;
        int x=p.first;

        if(vis[x]) continue;
        vis[x]=true;
        for(int i=0;i<v[x].size();i++){
            int e=v[x][i].first;
            int w=v[x][i].second;
            //cout<<dist[x]<<".";
            if(dist[x]+w<dist[e])
                dist[e]=dist[x]+w;
            s.insert({dist[e],e});
        }
    }
}
int main(){
    int i,j,k,w,n;
    n=5;
    pair<int,int> p;
    for(i=0;i<n;i++){
        cin>>j>>k>>w;
        p = make_pair(k,w);
        v[j].push_back(p);
        p = make_pair(j,w);
        v[k].push_back(p);
    }
    //cout<<v[0][0].first<<endl;
    dijkstra();
    for(i=0;i<4;i++) cout<<dist[i]<<" ";
}

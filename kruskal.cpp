#include<bits/stdc++.h>
using namespace std;
int edges,nodes;
const int maxx=1e4+5;
int id[maxx];
pair <int, pair <int, int> > p[maxx];
void initialize(){
    for(int i=0;i<maxx;i++) id[i]=i;
    //for(int i=0;i<maxx;i++) cout<<id[i];
}
int find(int x){
    while(id[x]!=x){
        id[x]=id[id[x]];
        x=id[x];
    }
    return x;
}
void change(int x,int y){
    int p=find(x);
    int q=find(y);
    id[p]=id[q];
}
int kruskal(pair<int,pair<int,int>> p[]){
    int i,minc=0,x,y,cost;
    for(i=0;i<edges;i++){
        x=p[i].second.first;
        y=p[i].second.second;
        cost=p[i].first;
        if(find(x)!=find(y)){
            minc=minc+cost;
            change(x,y);
        }
    }
    return minc;
}
int main(){
    int i,j,k,n,x,y,w;
    initialize();
    cin>>nodes>>edges;
    for(i=0;i<edges;i++){
        cin>>x>>y>>w;
        p[i]=make_pair(w,make_pair(x,y));
    }
    sort(p,p+edges);
    cout<<kruskal(p);
    return 0;
}

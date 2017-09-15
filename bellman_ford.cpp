#include<bits/stdc++.h>
using namespace std;
vector<int> v[2000+10];
int dist[1000+10];

void bf(){
    for(i=0;i<m+2;i++){
        v[i].clear();
        dis[i]=2e9;
    }
    for(i=0;i<m;i++){
        cin>>from>>next>>weight;
        v[i].push_back(from);
        v[i].push_back(next);
        v[i].push_back(weight);
    }
    dist[0]=0;
    for(i=0;i<n-1;i++){
        int j=0;
        while(v[j].size()!=0){
            if(dist[v[j][0]]+v[j][2]<dist[v[j][1]){
                dist[v[j][1]]=dist[v[j][0]]+v[j][2];
            }
            j++;
        }
    }
}

int main(){
    bf();
    cout<<dist[1];
}

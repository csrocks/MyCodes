#include<bits/stdc++.h>
using namespace std;
void maxheap(vector<int>* a,int i,int n){
    int left=2*i;
    int right=left+1;
    int l;
    if(left<=n&&a[left]>a[i]) l=left;
    else l=i;
    if(right<=n&&a[right]>a[l]) l=right;
    if(l!=i){
        swap(a[i],a[l]);
        maxheap(a,l,n);
    }
    return;
}
void build(vector<int>* a,int n){
    for(int i=n/2;i>=1;i--){
        maxheap(a,i,n);
    }
}
void add(vector<int>* a,int x,int& n){
    (*a).push_back(x);
    n++;
    build(a,n);
}
int main(){
    int i,j,k,n,q;
    cin>>n;
    vector <int> a;
    for(i=0;i<n;i++){
        cin>>k;
        a.push_back(k);
    }
    cin>>q;
    while(q--){
        cin>>k;
        if(k==1){
            cin>>j;
            add(&a,j,n);
        }
        else{
            cout<<"a[1]"<<endl;
        }
    }
}

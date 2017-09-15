#include<bits/stdc++.h>
using namespace std;
void maxheap(int a[],int i,int n){
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
void build(int a[],int n){
    for(int i=n/2;i>=1;i--){
        maxheap(a,i,n);
    }
}
void hsort(int a[],int n){
    build(a,n);
    for(int i=n;i>1;i--){
        swap(a[1],a[i]);
        maxheap(a,1,i-1);
    }
}
int main(){
    int i,j,k,n;
    cin>>n;
    for(i=1;i<=n;i++)){
        cin>>a[i];
        if(i<3) cout<<"-1"<<endl;
        else{
            hsort(a,n);
            for(j=1;j<=n;j++) cout<<a[j];
        }
    }
}

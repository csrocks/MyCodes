#include<bits/stdc++.h>
using namespace std;
void swap(int &i, int &j){
    int k;
    k=i;
    i=j;
    j=k;
}
void max_heapify(int a[], int i, int n){
    int left=2*i;
    int right=left+1;
    int largest,k;
    if(left<=n && a[left]>a[i]) largest=left;
    else largest=i;
    if(right<=n && a[right]>a[largest]) largest=right;
    if(largest!=i){
        swap(a[largest],a[i]);
        max_heapify(a,largest,n);
    }
}
void build(int a[],int n){
    int i;
    for(i=n/2;i>=1;i--){
        max_heapify(a,i,n);
    }
}
void heap_sort(int a[],int n){
    int k,i;
    build(a,n);
    for(i=n;i>1;i--){
        swap(a[1],a[i]);
        max_heapify(a,1,i-1);
    }
}
int main(){
    int i,j,k;
    int a[9]={-1,5,3,4,1,2,9,8,7};
    heap_sort(a,8);
    for(i=1;i<=8;i++) cout<<a[i]<<" ";
}

#include<iostream>
using namespace std;
void counting_sort(int *a,int *b,int n){
    int i,j,k;
    k=a[0];
    for(i=0;i<n;i++) if(a[i]>k) k=a[i];
    k++;
    int c[k];
    for(i=0;i<k;i++) c[i]=0;
    for(i=0;i<n;i++) c[a[i]]++;
    for(i=1;i<k;i++) c[i]+=c[i-1];
    for(i=n-1;i>=0;i--){
        b[c[a[i]]-1]=a[i];
        c[a[i]]--;
    }
}
int main(){
    int i,j,k;
    int n=6;
    int a[]={9,2,5,13,5,6};
    int b[n];
    for(i=0;i<n;i++) b[i]=0;
    counting_sort(a,b,n);
    for(i=0;i<n;i++) cout<<b[i]<<" ";
}

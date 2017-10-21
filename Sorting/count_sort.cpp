#include<iostream>
using namespace std;
void counts(int *a, int n){
    int i,j,k;
    k=a[0];
    for(i=0;i<n;i++) if(a[i]>k) k=a[i];
    k++;
    int c[k];
    for(i=0;i<k;i++) c[i]=0;
    for(i=0;i<n;i++) c[a[i]]++;
    for(i=0;i<k;i++){
        for(j=0;j<c[i];j++) cout<<i<<" ";
    }
}
int main(){
    int i,j,k;
    int n=6;
    int a[]={9,2,5,13,5,6};
    counts(a,n);
}

#include<iostream>
#include<cstring>
using namespace std;
void selection_sort(int *a,int n){
    int i,j,k,r,s;
    for(i=0;i<n;i++){
        k=a[i]; s=i;
        for(j=i;j<n;j++){
            if(a[j]<k) {k=a[j]; s=j;}
        }
        a[s]=a[i];
        a[i]=k;
    }
}
int main(){
    int i,j,k;
    int n=6;
    int a[]={2,5,1,6,9,0};
    selection_sort(a,n);
    for(i=0;i<n;i++) cout<<a[i];
}

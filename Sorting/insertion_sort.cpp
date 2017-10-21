#include<iostream>
using namespace std;
void insertions(int *a,int n){
    int i,j,k;
    for(i=0;i<n-1;i++){
        for(j=i;j>=0;j--){
            if(a[j]>a[j+1]){
                k=a[j];
                a[j]=a[j+1];
                a[j+1]=k;
            }
            else break;
        }
    }
}
int main(){
    int i;
    int n=6;
    int a[]={5,1,6,2,8,0};
    insertions(a,n);
    for(i=0;i<n;i++) cout<<a[i];
}

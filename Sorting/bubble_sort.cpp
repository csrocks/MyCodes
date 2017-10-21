#include<iostream>
using namespace std;
int main(){
    int i,j=0,k,n;
    int a[4]={1,2,3,1};
    n=4;
    while(j==0){//for(x=0;x<n;x++)
        j=1;
        for(i=0;i<n-1;i++){
            if(a[i]>a[i+1]){
                k=a[i];
                a[i]=a[i+1];
                a[i+1]=k;
                j=0;
            }
        }
    }
    for(i=0;i<n;i++) cout<<a[i]<<" ";
}

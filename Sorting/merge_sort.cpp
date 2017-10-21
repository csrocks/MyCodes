#include<iostream>
using namespace std;
void mg(int a[],int l,int m,int r){
    int i,j,k;
    int s=m-l+1;
    int t=r-m;
    int L[s],R[t];
    cout<<a[l]<<a[r]<<endl;
    for(i=0;i<s;i++){
        L[i]=a[l+i];
    }
    for(i=0;i<t;i++){
        R[i]=a[m+1+i];
    }

    i=0;j=0;k=l;
    while(i<s && j<t){
        if(L[i]<R[j]){
            a[k++]=L[i++];
        }
        else{
            a[k++]=R[j++];
        }
    }

    while(i<s){
        a[k++]=L[i++];
    }
    while(j<t){
        a[k++]=R[j++];
    }

}

void msort(int a[], int l,int r){
    int m;
    if(l<r){
        m=(l+r)/2;
        msort(a,l,m);
        msort(a,m+1,r);
        mg(a,l,m,r);
    }
}

int main(){
    int i,a[6]={1,1,6,4,9,1};
    msort(a,0,5);
    for(i=0;i<6;i++) cout<<a[i]<<" ";
}

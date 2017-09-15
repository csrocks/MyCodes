#include<bits/stdc++.h>
using namespace std;
void counts(int a[],int n,int mul){
    int i,cnt[10]={0},op[n],k;
    for(i=1;i<10;i++) cnt[i]=0;
    for(i=0;i<n;i++){
        k=(a[i]/mul)%10;
        cnt[k]++;
    }

    for(i=1;i<11;i++){
        cnt[i]+=cnt[i-1];
    }
    //for(i=0;i<n;i++) cout<<cnt[i];
    //for(i=0;i<n;i++) cout<<op[i]<<" ";
    for(i=n-1;i>=0;i--){
        k=(a[i]/mul)%10;
        //cout<<k<<endl;
        op[cnt[k]-1]=a[i];
        cnt[k]--;
    }

    for(i=0;i<n;i++) a[i]=op[i];
}
void radixs(int *a,int n){
    int i,k,mul=1,maxx;
    maxx=a[0];
    for(i=0;i<n;i++) if(a[i]>maxx) maxx=a[i];
    //cout<<maxx;
    while(maxx){
        counts(a,n,mul);
        mul*=10;
        maxx/=10;
    }
}
int main(){
    int i,a[10]={5,9,3,6,2,0,7,1,8,4};
    radixs(a,10);
    for(i=0;i<10;i++) cout<<a[i]<<" ";
}

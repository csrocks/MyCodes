#include<bits/stdc++.h>
using namespace std;
int func(int x){
    return (2*x*x-12*x+7);
}
int search(int l,int r){
    int i;
    for(i=0;i<200;i++){
        int mid1=(2*l+r)/3;
        int mid2=(l+2*r)/3;
        if(func(mid1)<func(mid2)) r=mid2;
        else l=mid1;
    }
    int x=l;
    return func(x);
}
int main(){
    int i,j,k,n;
    cin>>n;
    while(n--){
        cin>>i>>j;
        cout<<search(i,j);
    }
}

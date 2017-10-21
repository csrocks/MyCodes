#include<iostream>
using namespace std;

int partition(int *a,int l,int r){
    int i,left,right,pivot_i;
    pivot_i=a[l];
    left=l; right=r;
    while(left<right){
        while(a[left]<=pivot_i) left++;
        while(a[right]>=pivot_i) right--;
        if(left<right){
            i=a[left];
            a[left]=a[right];
            a[right]=i;
        }
    }
    a[l]=a[right];
    a[right]=pivot_i;
    return right;
}

void quicks(int *a, int l, int r){
    int pivot;
    if(l<r){
        pivot=partition(a,l,r);
        quicks(a,l,pivot-1);
        quicks(a,pivot+1,r);
    }
    return;
}
int main(){
    int i,j,k;
    int n=6;
    int a[]={2,5,1,6,9,0};
    quicks(a,0,5);
    for(i=0;i<6;i++) cout<<a[i];
}

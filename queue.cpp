#include<bits/stdc++.h>
using namespace std;
void enqueue(int* que,int x,int &count,int &rear, int ar_size){
    if(count==ar_size) cout<<"Full";
    else{
        que[rear]=x;
        rear=(rear+1)%ar_size;
        count++;
    }
}
void dequeue(int* que,int &count,int &front,int ar_size){
    if(count==0) cout<<"Over";
    else{
        que[front]=0;
        front=(front+1)%ar_size;
        count--;
    }
}
void front(int* que, int front){
    return que[front];
}
int size(int count){
    return count;
}
bool isEmpty(int count){
    return count==0;
}
int main(){
    int i,j,k;
}

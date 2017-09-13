#include<bits/stdc++.h>
using namespace std;

typedef struct node{
    int data;
    struct node* next;
}node;
node* head=NULL;
node* p=NULL;
node* create(){
    node* temp;
    temp=(node*)malloc(sizeof(node));
    temp->next=NULL;
    return temp;
}
void add(int i,int k){
    node *temp;
    temp=create();
    temp->data=i;
    if(head==NULL) head=temp;
    else if(k==-1){//to add last in the list
        p=head;
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=temp;
    }
    else if(k==0){//to add first in the list
        p=head;
        head=temp;
        temp->next=p;
    }
    else{
        k--;
        p=head;
        node* q,*temp;
        q=p->next;
        while(k--){
            p=p->next;
            q=q->next;
        }
        temp=create();
        temp->data=i;
        p->next=temp;
        temp->next=q->next;
        free(q);
    }
}
void deletekey(int i){
    p=head;
    node *q=head;
    if(p->data==i){
        if(q!=NULL) head=q->next;
        free(p);
    }
    else{
        while(q->next!=NULL){
            q=q->next;
            if(q->data==i){
                if(q->next==NULL){
                    //cout<<q->data<<endl;
                    p->next=NULL;
                    free(q);
                    continue;
                }
                p->next=q->next;
                free(q);
                q=p->next;
            }
            p=p->next;
        }
    }
    return;
}
void print(){
    p=head;
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
}
int main(){
    for(int i=1;i<6;i++) add(i,-1); //-1 to add last
    for(int i=6;i<11;i++) add(i,0); //0 to add first
    add(23,5); //to add at position 5 (0 being the head)
    deletekey(5);
    print();
}

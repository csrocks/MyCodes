#include<bits/stdc++.h>
using namespace std;

class node{
  public:
    int data;
    node *next;

    node(int x){
      data = x;
      next = NULL;
    }
};

node *head = NULL;

void insert_front(int data){
  node *temp = new node(data);
  temp->next = head;
  head = temp;
}

void insert_back(int data){
  node *temp = new node(data);

  node *t = head;
  while(t->next) t = t->next;
  t->next = temp;
}

void delete_node(int data){
  node *temp = head;
  if(temp->data == data){
    head = temp->next;
    free(temp);
  }
  
  while(temp->next){
    if(temp->next->data == data){
      node *curr = temp->next;
      temp->next = curr->next;
      free(curr);
    }
    temp = temp->next;
  }
}

void print(){
  node *temp = head;
  while(temp){
    cout << temp->data <<" ";
    temp = temp->next;
  }
}

int main(){
  for (int i = 10; i > 0; i--) insert_front(i);
  for (int i = 11; i <= 20; i++) insert_back(i);
  delete_node(9);
  print();
}
#include<bits/stdc++.h>
using namespace std;

class node{
  public:
    int data;
    node *left;
    node *right;
    node(int x){
      data = x;
      left = NULL;
      right = NULL;
    }
};

node *head = NULL;

//insert in level order
void insert(int data){
  if(!head) head = new node(data);
  queue<node*> q;
  q.push(head);

  while(!q.empty()){
    node *temp = q.front(); q.pop();
    if(!temp->left){
      temp->left = new node(data);
      break;
    }
    else q.push(temp->left);

    if(!temp->right){
      temp->right = new node(data);
      break;
    }
    else q.push(temp->right);
  }
}

void inorder(node *root){
  if(!root) return;
  if(root->left) inorder(root->left);
  cout << root->data <<" ";
  if(root->right) inorder(root->right);
}

void preorder(node *root){
  if(!root) return;
  cout << root->data <<" ";
  if(root->left) inorder(root->left);
  if(root->right) inorder(root->right);
}

void postorder(node *root){
  if(!root) return;
  if(root->left) inorder(root->left);
  if(root->right) inorder(root->right);
  cout << root->data <<" ";
}

int main(){
  for (int i = 10; i > 0; i--) insert(i);
  // delete_node(9);
  inorder(head);
}
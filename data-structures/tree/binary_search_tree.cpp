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

node* insert(node *root, int data){
  if(!root) return new node(data);
  if(root->data < data) root->right = insert(root->right, data);
  else root->left = insert(root->left, data);
  return root;
}

void insert_itr(int data){
  node *new_node = new node(data);
  node *temp = head, *prev = NULL;

  while(temp){
    prev = temp;
    if(temp->data < data) temp = temp->right;
    else temp = temp->left;
  }
  if(!prev) head = new_node;
  else if(prev->data < data) prev->right = new_node;
  else prev->left = new_node;
}

node* delete_node(node *root, int data){
  if(!root) return NULL;
  if(data < root->data) root->left = delete_node(root->left, data);
  else if(data > root->data) root->right = delete_node(root->right, data);
  else{
    if(!root->left){
      node * temp = root->right;
      free(root);
      return temp;
    }
    else if(!root->right){
      node * temp = root->left;
      free(root);
      return temp;
    }
    node * temp = root->right;
    while(temp->left) temp = temp->left;
    root->data = temp->data;
    root->right = delete_node(root->right, root->data);
  }
  return root;
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
  for (int i = 10; i > 0; i--) head = insert(head, i);
  for (int i = 11; i <= 20; i++) insert_itr(i);
  head = delete_node(head, 9);
  head = delete_node(head, 5);
  inorder(head); cout<<endl;
  preorder(head); cout<<endl;
  postorder(head);
}
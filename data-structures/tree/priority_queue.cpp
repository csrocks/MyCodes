#include<bits/stdc++.h>
using namespace std;

vector<int> arr;

void max_heapify(int i){
  int n = arr.size();
  int left = 2*i;
  int right = left + 1;
  int largest = i;
  if(left < n && arr[i] < arr[left]) largest = left;
  if(right < n && arr[largest] < arr[right]) largest = right;

  if(largest != i){
    swap(arr[i], arr[largest]);
    max_heapify(largest);
  }
}

int top(){
  return arr[0];
}

int pop(){
  int n = arr.size();
  if(n == 0) return -1;
  int maxi = arr[0];
  
  arr[0] = arr[n-1];
  max_heapify(0);
  
  return maxi;
}

void edit(int i, int val){
  if(val < arr[i]) return;
  arr[i] = val;

  while(i > 0 && arr[i/2] < arr[i]){
    swap(arr[i/2], arr[i]);
    i /= 2;
  }
}

void insert(int val){
  arr.push_back(-1);
  edit(arr.size()-1, val); 
}

int main(){
  insert(2); insert(8); insert(5);
  cout << top() << " ";
  cout << pop() << " ";
  cout << top() << " ";
}
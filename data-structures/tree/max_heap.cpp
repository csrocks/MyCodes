#include<bits/stdc++.h>
using namespace std;

void max_heapify(vector<int> &arr, int i){
  int n = arr.size();
  int left = 2*i;
  int right = left + 1;
  int largest = i;
  if(left < n && arr[i] < arr[left]) largest = left;
  if(right < n && arr[largest] < arr[right]) largest = right;

  if(largest != i){
    swap(arr[i], arr[largest]);
    max_heapify(arr, largest);
  }
}

void build_max_heap(vector<int> &arr){
  int n = arr.size();
  for(int i = n/2; i >= 0; i--){
    max_heapify(arr, i);
  }
}

int main(){
  vector<int> arr = {1,4,3,7,8,9,10};
  build_max_heap(arr);
  for(int i: arr) cout << i << " ";
}
#include<bits/stdc++.h>
using namespace std;

void min_heapify(vector<int> &arr, int i){
  int n = arr.size();
  int left = 2*i;
  int right = left + 1;
  int smallest = i;
  if(left < n && arr[i] > arr[left]) smallest = left;
  if(right < n && arr[smallest] > arr[right]) smallest = right;

  if(smallest != i){
    swap(arr[i], arr[smallest]);
    min_heapify(arr, smallest);
  }
}

void build_min_heap(vector<int> &arr){
  int n = arr.size();
  for(int i = n/2; i >= 0; i--){
    min_heapify(arr, i);
  }
}

void heap_sort(vector<int> &arr){
  build_min_heap(arr);
  for (int i = 1; i < arr.size(); i++){
    min_heapify(arr, i);
  }
  
}

int main(){
  vector<int> arr = {8,4,3,10,1,9,7};
  heap_sort(arr);
  for(int i: arr) cout << i << " ";
}
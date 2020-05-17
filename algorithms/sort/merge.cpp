#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high){
  int a[high-low+1];
  int l = low, h = mid+1, k = 0;
  
  while(l <= mid && h <= high){
    if(arr[l] <= arr[h]) a[k++] = arr[l++];
    else a[k++] = arr[h++];
  }

  while(l <= mid) a[k++] = arr[l++];
  while(h <= high) a[k++] = arr[h++];

  for(int i = 0; i < k; i++) arr[low + i] = a[i];
}

void merge_sort(vector<int> &arr, int low, int high){
  if(low >= high) return;
  int mid = (low + high)/2;
  merge_sort(arr, low, mid);
  merge_sort(arr, mid+1, high);
  merge(arr, low, mid, high);
}

int main(){
  vector<int> arr = {4, 5, 1, 3, 2};
  merge_sort(arr, 0, 4);
  for (int i = 0; i < arr.size(); i++){
    cout << arr[i] << " ";
  }  
} 
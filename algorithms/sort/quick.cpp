#include<bits/stdc++.h>
using namespace std;

int generate_random(int low, int high){
  return low + rand()%(high-low+1);
}

int partition(vector<int> &arr, int low, int high){
  int p = generate_random(low, high);
  swap(arr[low], arr[p]);
  int pivot = arr[low];
  int j = low + 1;

  for(int i = low+1; i <= high; i++){
    if(arr[i] < pivot) swap(arr[i], arr[j++]);
  }

  swap(arr[low], arr[j-1]);
  return j-1;
}

void quick_sort(vector<int> &arr, int low, int high){
  if(low >= high) return;
  int p = partition(arr, low, high);
  quick_sort(arr, low, p-1);
  quick_sort(arr, p+1, high);
}

int main(){
  vector<int> arr = {4, 5, 1, 3, 2};
  quick_sort(arr, 0, 4);
  for (int i = 0; i < arr.size(); i++){
    cout << arr[i] << " ";
  }  
} 
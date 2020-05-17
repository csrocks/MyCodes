#include<bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int> &arr){
  int n = arr.size();
  for (int i = 0; i < n-1; i++){
    int k = arr[i];
    int j;
    for (j = i; j >0; j--){
      if(arr[j-1] > arr[j]) arr[j] = arr[j-1];
      else break;
    }
    arr[j] = k;
  }
}

int main(){
  vector<int> arr = {4, 5, 1, 3, 2};
  insertion_sort(arr);
  for (int i = 0; i < arr.size(); i++){
    cout << arr[i] << " ";
  }  
} 
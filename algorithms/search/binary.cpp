#include<bits/stdc++.h>
using namespace std;

int search_binary(int key, vector<int> arr){
  int low = 0, high = arr.size();
  while(low <= high){
    int mid = (low + high)/2;
    if(arr[mid] < key) low = mid + 1;
    else if(arr[mid] > key) high = mid - 1;
    else return mid;
  }
  return -1;
}

int main(){
  vector<int> arr = {1, 2, 3, 4, 5};
  cout << search_binary(4, arr);
} 
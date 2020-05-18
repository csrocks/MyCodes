#include<bits/stdc++.h>
using namespace std;

int ternary_binary(int key, vector<int> arr){
  int low = 0, high = arr.size();
  while(low <= high){
    int mid1 = low + (high - low)/3; //important, avoids going into a infinite loop
    int mid2 = high - (high - low)/3; //important, avoids going into a infinite loop
    if(arr[mid1] == key) return mid1;
    if(arr[mid2] == key) return mid2;

    if(key < arr[mid1]) high = mid1 - 1;
    else if(key > arr[mid2]) low = mid2 + 1;
    else{ low = mid1 + 1; high = mid2 - 1;}
  }
  return -1;
}

int main(){
  vector<int> arr = {1, 2, 3, 4, 5};
  cout << ternary_binary(4, arr);
} 
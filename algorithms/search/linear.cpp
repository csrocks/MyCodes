#include<bits/stdc++.h>
using namespace std;

int linear_search(int key, vector<int> arr){
  for(int i=0; i<arr.size(); i++){
    if(arr[i] == key) return i;
  }
  return -1;
}

int main(){
  vector<int> arr = {1, 2, 3, 4, 5};
  cout << linear_search(4, arr);
} 
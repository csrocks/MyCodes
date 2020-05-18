#include<bits/stdc++.h>
using namespace std;

void bucket_sort(vector<float> &arr){
  int n = arr.size();
  vector<float> bucket[n];
  
  for(auto i: arr){
    int k = n*i;
    bucket[k].push_back(i); 
  }
  for(auto i: bucket) sort(i.begin(), i.end());

  int k = 0;
  for(auto i: bucket){
    for(auto j: i) arr[k++] = j;
  }
}

int main(){
  vector<float> arr = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434}; 
  bucket_sort(arr);
  for (auto i: arr) cout << i << " ";
}

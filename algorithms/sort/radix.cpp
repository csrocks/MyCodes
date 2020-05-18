#include<bits/stdc++.h>
using namespace std;

void count_sort(vector<int> &arr, int mul){
  int n = arr.size();
  int freq[10] = {0}, a[n];

  for(int i: arr) freq[(i/mul)%10]++;
  
  for(int i = 1; i < 10; i++) freq[i] += freq[i-1];

  for(int i = n-1; i >= 0; i--){
    int k = (arr[i]/mul)%10;
    a[freq[k]-1] = arr[i]; 
    freq[k]--;
  }

  for(int i = 0; i < n; i++) arr[i] = a[i];
}

void radix_sort(vector<int> &arr){
  int maxi = *max_element(arr.begin(), arr.end());
  int mul = 1;
  
  while(maxi){
    count_sort(arr, mul);
    mul *= 10;
    maxi /= 10;
  }
}

int main(){
  vector<int> arr = {10,21,17,34,44,11,654,123};
  radix_sort(arr);
  for (int i: arr) cout << i << " ";
} 
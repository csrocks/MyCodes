#include<bits/stdc++.h>
using namespace std;

void count_sort(vector<int> &arr){
  int maxi = *max_element(arr.begin(), arr.end());
  vector<int> freq(maxi+1, 0);
  for(int i: arr) freq[i]++;

  int j = 0;
  for(int i = 0; i <= maxi; i++){
    int k = freq[i];
    while(k--) arr[j++] = i;
  }
}

void count_sort_2(vector<int> &arr){
  int n = arr.size();
  int freq[10] = {0}, a[n];

  for(int i: arr) freq[i]++;
  
  for(int i = 1; i < 10; i++) freq[i] += freq[i-1];

  for(int i = n-1; i >= 0; i--){
    a[freq[arr[i]]-1] = arr[i]; 
    freq[arr[i]]--;
  }

  for(int i = 0; i < n; i++) arr[i] = a[i];
}

int main(){
  vector<int> arr = {4, 5, 1, 5, 3, 1, 0, 2};
  count_sort(arr);
  count_sort_2(arr);
  for (int i: arr) cout << i << " ";
} 
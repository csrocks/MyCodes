#include<bits/stdc++.h>
using namespace std;

void cal_lps(string key, vector<int> &lps){
  lps[0] = 0;
  int m = key.size();
  
  int i = 1, len = 0;
  while(i < m){
    if(key[i] == key[len]) lps[i++] = ++len;
    else{
      if(len) len = lps[len-1];
      else lps[i++] = 0;
    }
  }
}

vector<int> kmp(string key, string text){
  int n = text.size(), m = key.size();
  vector<int> lps(m), ans;
  cal_lps(key, lps);
  
  int i=0, j=0;
  while(i < n){
    if(text[i] == key[j]){ i++; j++; }
    
    if(j == m){
      ans.push_back(i-j);
      j = lps[j-1];
    }
    else if(i < n && text[i] != key[j]){
      if(j) j = lps[j-1];
      else i++; 
    }
  }
  return ans;
}

int main(){
  string key = "aba";
  string text = "ababaaaaaba";
  vector<int> indices = kmp(key, text);
  for (int i : indices) cout << i << " ";
}
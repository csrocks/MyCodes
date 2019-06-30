#include <bits/stdc++.h>
using namespace std;
vector<int> create_lps(string pat){
	int m = pat.size();
	vector<int> lps(m,0);
	lps[0]=0;
	int i=1, j=0;
	while(i < m){
		if(pat[i]==pat[j]) lps[i++] = ++j;
		else{
			if(j!=0) j = lps[j-1];
			else lps[i++]=0;
		}
	}
	return lps;
}

vector<int> kmp(string text, string pat){
	int n = text.size();
	int m = pat.size();
	vector<int> lps = create_lps(pat);
	vector<int> ans;
	int i=0, j=0;
	while(i<n){
		if(text[i] == pat[j]){ i++; j++; }
		if(j==m){
			ans.push_back(i-j);
			j=lps[j-1];
		}
		else if(i<n && text[i]!=pat[j]){
			if(j!=0) j = lps[j-1];
			else i++;
		}
	}
	return ans;
}

int main(){
	string text = "abcabdabababdcdcd";
	string pat = "abab";
	vector<int> ans = kmp(text, pat);
	for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
}

#include<bits/stdc++.h>
using namespace std;
bool isattacked(int x, int y, vector<int>* board, int n){
	int i,j;
	for(i=0;i<n;i++){
		if(board[x][i]==1) return true;
		if(board[i][y]==1) return true;
		for(j=0;j<n;j++){
			if(((i+j==x+y)||(i-j==x-y))&&board[i][j]==1) return true;
		}
	}
	return false;
}
bool nqueen(vector<int>* board,int n,int t){
	if(t==0) return true;
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(isattacked(i,j,board,n)) continue;
			board[i][j]=1;
			if(nqueen(board,n,t-1)) return true;
			board[i][j]=0;
		}
	}
	return false;
}

int main(){
	int i,j,k,n;
	cin>>n;
	vector <int> board[n];
	for(i=0;i<n;i++) for(j=0;j<n;j++) board[i].push_back(0);
	bool b=nqueen(board,n,n);
	if(b==true){
		cout<<"YES"<<endl;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				cout<<board[i][j]<<" ";
			}
		cout<<endl;
		}
	}
	else cout<<"NO";
}

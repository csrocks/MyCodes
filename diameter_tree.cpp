#include<bits/stdc++.h>
using namespace std;
typedef struct node{
    int data;
    struct node* left,*right;
}node;
node* root=NULL;
node* p=NULL;
node* create(int x){
    node* temp;
    temp=(node*)malloc(sizeof(node));
    temp->data=x;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
void add(string a,int x){
    node *temp;
    temp=create(x);
    if(root==NULL) root=temp;
    else{
        p=root;
        int s=a.size(),i;
        for(i=0;i<s-1;i++){
            if(a[i]=='L') p=p->left;
            else p=p->right;
        }
        if(a[i]=='L') p->left=temp;
        else p->right=temp;
    }
    return;
}
int height(node* temp);

int diameter(node* temp){
     if(temp==NULL) return 0;
     int lheight=height(temp->left);
     int rheight=height(temp->right);
     int ldiameter=diameter(temp->left);
     int rdiameter=diameter(temp->right);
     return max(lheight+rheight+1, max(ldiameter,rdiameter));
}
int height(node* temp){
    if(temp==NULL) return 0;
    int lheight=height(temp->left);
    int rheight=height(temp->right);
    return 1+max(lheight,rheight);
}
int compare(string a,string b){
    int i=0,j=0,as=a.size(),bs=b.size();
    if(as<bs) return 0;
    else if(bs<as) return 1;
    else{
    	while(i!=as && j!=bs){
        	if(a[i]=='L'&&b[j]=='R') return 0;
        	else if(a[i]=='R'&&b[j]=='L') return 1;
        	i++; j++;
    	}
    }
}
void sort(string* st, int n){
	int i,j,k;
	string temp;
	for(j=2;j<n;j++){
		for(i=2;i<n;i++){
			//cout<<st[i]<<" "<<st[i+1]<<" "<<compare(st[i],st[i+1])<<endl;
			if(compare(st[i],st[i+1])){
				temp=st[i];
				st[i]=st[i+1];
				st[i+1]=temp;
			}
		}
	}
}
int main(){
    int i,j,k,n;
    cin>>n>>k;
    string a,st[n+1];
    int arr[n+1];
    add(" ",k);
    int t=n-1;
    while(t--){
        cin>>a>>k;
        st[k]=a;
    }
    sort(st,n);
    for(i=2;i<n+1;i++) add(st[i],i);
    cout<<diameter(root);
}

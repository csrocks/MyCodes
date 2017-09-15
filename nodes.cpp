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
    if(root==NULL){
    	node *temp;
    	temp=create(x);
    	root=temp;
    }
    else{
        p=root;
        int s=a.size(),i;
        for(i=0;i<s-1;i++){
            if(a[i]=='L'){
            	if(p->left!=NULL){
            		p=p->left;
            	}
            	else{
    				temp=create(-1);
    				p->left=temp;
    				p=p->left;
            	}
            }
            else{
            	if(p->right!=NULL){
            		p=p->right;
            	}
            	else{
    				temp=create(-1);
    				p->right=temp;
    				p=p->right;
            	}
            }
        }
	    if(a[i]=='L'){
	    	if(p->left==NULL){
	    		temp=create(x);
	    		p->left=temp;
	    	}
	    	else p->left->data=x;
	    }
	    else{
	    	if(p->right==NULL){
	    		temp=create(x);
	    		p->right=temp;
	    	}
	    	else p->right->data=x;
	    }
        return;
    }
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
void bfs(int n){
	int k,i;
	bool vis[n];
	int level[n];
	for(i=0;i<n;i++){
		vis[i]=false;
		level[i]=0;
	}
	p=root;
	queue <node*> q;
	q.push(p);
	level[p->data]=1;
	vis[p->data]=true;
	while(!q.empty()){
		p=q.front();
		q.pop();
		cout<<level[p->data]<<" "<<p->data<<endl;
		if(p->left!=NULL){
			if(vis[p->left->data]==false){
				level[p->left->data]=level[p->data]+1;
				vis[p->left->data]=true;
				q.push(p->left);
			}
		}
		if(p->right!=NULL){
			if(vis[p->right->data]==false){
				level[p->right->data]=level[p->data]+1;
				vis[p->right->data]=true;
				q.push(p->right);
			}
		}
	}
}
int main(){
    int i,j,k,n;
    cin>>n>>k;
    string a;
    add(" ",k);
    for(i=1;i<n;i++){
    	cin>>a>>k;
    	add(a,k);
    }
    //bfs(n);
    cout<<diameter(root);
}

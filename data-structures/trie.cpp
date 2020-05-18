#include<bits/stdc++.h>
using namespace std;
const int tw = 26;

class trie{
  public:
    trie *next[tw];
    bool isword;

    trie(){
      for(int i=0; i<tw; i++) next[i] = NULL;
      isword = false;
    }
};

trie *head = new trie();

void insert(string word){
  trie *temp = head;
  for(int i=0; i<word.size(); i++){
    int index = word[i] - 'a';
    if(!temp->next[index]) temp->next[index] = new trie();
    temp = temp->next[index]; 
  }
  temp->isword = true;
}

bool search(string word){
  trie *temp = head;
  for(int i=0; i<word.size(); i++){
    int index = word[i] - 'a';
    if(!temp->next[index]) return false;
    temp = temp->next[index]; 
  }
  return true;
}

bool empty_next(trie* root){
  for(int i=0; i<tw; i++) if(root->next[i]) return false;
  return true;
}

trie* remove(trie *root, string word, int i){
  if(!root) return NULL;

  if(i == word.size()){
    root->isword = false;
  }
  else{
    int index = word[i] - 'a';
    root->next[index] = remove(root->next[index], word, i+1);
  }

  if(empty_next(root) && !root->isword){ delete(root); root=NULL;}

  return root;
}

int main(){
  insert("abc"); insert("nbd"); insert("nbdfg");
  head = remove(head, "abc", 0);
  cout << search("abc") << " ";
  head = remove(head, "nbd", 0);
  cout << search("nbdfg") << " ";
}
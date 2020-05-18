#include<bits/stdc++.h>
using namespace std;

class Stack{
  public:
    vector<int> a;
    void push(int x);
    int pop();
    int top();
    bool empty();
    int size();
};

void Stack::push(int x){
  a.push_back(x);
}

int Stack::pop(){
  int top = a.back();
  a.pop_back();
  return top;
}

int Stack::top(){
  if(a.size() == 0) return -1;
  return a.back();
}

bool Stack::empty(){
  return a.size() == 0;
}

int Stack::size(){
  return a.size();
}

int main(){
  Stack s;
  s.push(2); s.push(1); s.push(3);
  cout << s.pop() << " ";
  cout << s.top() << " ";
  cout << s.empty() << " ";
  cout << s.size() << " ";
}
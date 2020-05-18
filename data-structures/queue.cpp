#include<bits/stdc++.h>
using namespace std;

class Queue{
  int start;
  public:
    vector<int> a;
    void push(int x);
    int pop();
    int front();
    bool empty();
    int size();

    Queue(){
      start = 0;
    }
};

void Queue::push(int x){
  a.push_back(x);
}

int Queue::pop(){
  int f = a[start];
  start++;
  if(start == 10) a.erase(a.begin(), a.begin()+100);
  return f;
}

int Queue::front(){
  if(a.size() == 0) return -1;
  return a[start];
}

bool Queue::empty(){
  return start == a.size();
}

int Queue::size(){
  return a.size()-start;
}

int main(){
  Queue q;
  q.push(2); q.push(1); q.push(3);
  cout << q.front() << " ";
  cout << q.pop() << " ";
  cout << q.front() << " ";
  cout << q.empty() << " ";
  cout << q.size() << " ";
}
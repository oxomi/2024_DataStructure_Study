#include <bits/stdc++.h>
using namespace std;


    const int MX = 1000005;
    int dat[2*MX +1];
    int head = MX, tail = MX;

    void push_front(int x){
        head--;
        dat[head] = x;
    }

    void push_back(int x){
        dat[tail] = x;
        tail++;
    }

    void pop_front(){
        head++;
    }

    void pop_back(){
        tail--;
    }

    int size(){
        return tail-head;
    }

    bool empty(){
        if(head == tail) return -1;
        else return 0;
    }

    int front(){
        return dat[head];
    }

    int back(){
        return dat[tail-1];
    }   

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);


    int N;
    cin >> N;

    while(N--){
                string op;
    cin >> op;

    if(op == "push_front"){
        int add;
        cin >> add;
        push_front(add);
    }
    else if(op == "push_back"){
        int add;
        cin >> add;
        push_back(add);
    }
    else if(op == "pop_front"){
        if(empty()) cout << -1 << '\n';
        else {
            cout << front() << '\n';
            pop_front();
        }
    }    
    else if(op == "pop_back"){
        if(empty()) cout << -1 << '\n';
        else {
            cout << back() << '\n';
            pop_back();
        }
    }       
    else if(op == "size"){
        cout << size() << '\n';
    }
    else if(op == "empty"){
        if(empty()) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
    else if(op == "front"){
        if(empty()) cout << -1 << '\n';
        else cout << front() << '\n';
    }
    else { //back
        if(empty()) cout << -1 << '\n';
        else cout << back() << '\n';
    }
    }

    
}
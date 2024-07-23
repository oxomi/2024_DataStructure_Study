#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    deque<int> DQ;

    int N;
    cin >> N;

    while(N--){
        string op;
        cin >> op;

        if(op == "push_front"){
            int add;
            cin >> add;
            DQ.push_front(add);
        }
        else if(op == "push_back"){
            int add;
            cin >> add;
            DQ.push_back(add);
        }
        else if(op == "pop_front"){
            if(DQ.empty()) cout << -1 << '\n';
            else {
                cout << DQ.front() << '\n';
                DQ.pop_front();
            }
        }    
        else if(op == "pop_back"){
            if(DQ.empty()) cout << -1 << '\n';
            else {
                cout << DQ.back() << '\n';
                DQ.pop_back();
            }
        }       
        else if(op == "size"){
            cout << DQ.size() << '\n';
        }
        else if(op == "empty"){
            if(DQ.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if(op == "front"){
            if(DQ.empty()) cout << -1 << '\n';
            else cout << DQ.front() << '\n';
        }
        else { //back
            if(DQ.empty()) cout << -1 << '\n';
            else cout << DQ.back() << '\n';
        }
    }
}
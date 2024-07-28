#include <bits/stdc++.h>
using namespace std;

int main(){

    while(true){ //반복 횟수가 정해지지 않았을땐 이렇게 짜주면 됨
        string a;
        getline(cin, a);

        if(a ==  ".") break;

        stack<char> S;

        for(char c : a){
            if(c == '(' || c == '['){
                S.push(c);
            }
            else if(c == ')'){
                if(S.empty() || S.top() != '(') break;
                S.pop();
            }
            else if(c == ']'){
                if(S.empty() || S.top() != '[') break;
                S.pop();
            }
        }

        if(!S.empty()) cout << "no" << '\n';
        else cout << "yes" << '\n';

    }


}
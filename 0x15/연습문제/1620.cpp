#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> m;
string name[100005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int p_num, ans_num;
    cin >> p_num >> ans_num;

    for(int i = 1; i <= p_num; i++){
        cin >> name[i];
        m[name[i]] = i;
    }

    while(ans_num--){
        string answer;
        cin >> answer;
        if(isdigit(answer[0]) == 0){  // isdigit() - 문자열의 시작 스펠링을 통해 숫자인지 확인. 숫자가 아니면 0을 반환
            cout << m[answer] << '\n';
        }
        else{ //숫자일 경우
            cout << name[stoi(answer)] << '\n';  // stoi - string to int. 문자열을 숫자로 바꿔줌
        }
    }
}
//이분탐색과 투포인터로도 풀 수 있다고 함.
#include <bits/stdc++.h>
using namespace std;

unordered_set<string> s;

int main(){
    int num;
    cin >> num;

    while(num--){
        string name, log;
        cin >> name >> log;
        if(log == "enter") s.insert(name);
        else s.erase(name);
    }

    //순서대로 출려갛기 위해 벡터에 다시 담아주는 과정
    vector<string> ans(s.begin(), s.end());
    sort(ans.begin(), ans.end(), greater<string>()); //역순으로 출력하기 위함
    for(string c : ans) cout << c << '\n';

}
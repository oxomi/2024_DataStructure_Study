#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num;
    string a, b;

    cin >> num;


    for(int i = 0; i < num; i++){
        
        cin >> a >> b;
        int occur1[26] = {}, occur2[26] = {}; //입력 받을때마다 초기화할 수 있도록 여기 둬야함

        for(int j = 0; j < a.length(); j++){
            occur1[a[j] - 'a']++;
        }

        for(int j = 0; j < b.length(); j++){
            occur2[b[j] - 'a']++;
        }

        bool flag = 1;
        for(int j = 0; j < 26; j++){
            if(occur1[j] != occur2[j]){
                flag = 0;
                break;
            }
        }

        //와 대문자 안해줘서 틀렸다 ㅋㅋㅋㅋㅋㅋ ㅅㅂ
        if(flag) cout << "Possible" << '\n';
        else cout << "Impossible" << '\n';
        

    }

}
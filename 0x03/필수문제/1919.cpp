#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a1, a2;
    int occur1[26]={}, occur2[26]={};
    int len = 0;
    cin >> a1 >> a2;

    for(int i=0; i < a1.length(); i++){
        occur1[a1[i] - 'a']++; //string도 index 쓸수있음
    }

    for(int i=0; i < a2.length(); i++){
        occur2[a2[i] - 'a']++;
    }

    for(int i=0; i<26; i++){
        if(occur1[i] != occur2[i]){
            // if(occur1[i] > occur2[i]) len += (occur1[i] - occur2[i]);
            // else len += (occur2[i] - occur1[i]);
            len += abs(occur1[i] - occur2[i]); //절댓값 이용하면 되네 ㅋㅋ
        }
    }

    cout << len;


}
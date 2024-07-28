#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t[5], sum = 0;
    for(int i = 0; i <5; i++){
        cin >> t[i];
        sum += t[i];
    }
    sort(t, t+5);
    cout << sum/5 << '\n' << t[2];
}
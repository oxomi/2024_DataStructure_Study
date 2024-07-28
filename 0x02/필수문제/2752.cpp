#include <bits/stdc++.h>
using namespace std;

int main(){
    int t[3];
    for(int i = 0; i < 3; i++){
        cin >> t[i];
    }
    sort(t, t+3);
    for(int i = 0; i < 3; i++){
        cout << t[i] << " ";
    }
}
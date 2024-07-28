#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int a[N], v, cnt=0; 
    for(int i = 0; i< N; i++){
        cin >> a[i];
    }
    cin >> v;

    for(int i = 0; i< N; i++){
        if(a[i] == v) cnt++;
    }

    cout << cnt;
}
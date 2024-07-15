#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num;
    cin >> num;


    int x, Y=0, M=0;
    for(int i = 0; i < num; i++) {
        cin >> x;
        Y += (x / 30 + 1) * 10;
        M += (x / 60 +1) * 15;
    }

    if(Y == M) cout << "Y M " << Y;
    else{
        if(Y < M) cout << "Y " << Y;
        else if(Y > M) cout << "M " << M;
    }

}
#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    int sum = a * b * c;
    int cnt[10] = {};

    while(sum > 0){
        cnt[sum%10]++;
        sum /= 10;
    }


    for(int i = 0; i < 10; i++){
        cout << cnt[i] << '\n';
    }


}

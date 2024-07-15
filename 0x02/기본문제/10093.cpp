//범위가 10^15로 주어졌는데, 이는 int(21억)의 범위보다 휠씬 크므로 longlong을 사용해야 한다. 
#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    unsigned long long a, b;
    cin >> a >> b;

    if(a > b) swap(a, b);
    
    if(a==b) cout << 0 << '\n';
    else {
        cout << b-a-1 << '\n';
        for(unsigned long long i = a+1; i < b ; i++){
            cout << i << " ";
        }
    }


}
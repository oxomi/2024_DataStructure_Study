#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num[9];
    for(int i = 0; i < 9; i++){
        cin >> num[i];
    }

    int max = *max_element(num, num+9); //max_element는 반환값이 주솟값
    bool flag = false;
    cout << max << '\n';
    for(int i =0; i < 9 && flag == false; i++){
        if(max == num[i]) {
            cout << i+1;
            flag = true;
        }
    }

}
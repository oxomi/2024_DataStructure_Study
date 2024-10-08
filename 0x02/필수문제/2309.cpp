#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t[9], sum = 0;  
    for(int i = 0; i < 9; i++){
        cin >> t[i];
        sum += t[i];
    }
    sort(t, t + 9);

    int gap = sum - 100;
    bool found = false; 
    //found라는 플래그가 없으면 가짜 난쟁이 둘을 찾았어도 반복문이 종료되지 않아서 틀렸다고 채점됨.
    for(int i = 0; i < 9 && !found; i++){
        for(int j = i + 1; j < 9 && !found; j++){
            if(t[i] + t[j] == gap){
                t[i] = 0;
                t[j] = 0;
                found = true;
            }
        }
    }
    
    for(int i = 0; i < 9; i++){
        if(t[i] != 0) cout << t[i] << '\n';
    }

    return 0;
}

//아홉 난쟁이의 키를 더하여 100과의 차를 구하고, 그 차를 이루는 두 가짜난쟁이를 찾으면 되는 문제.
//수학적으로 접근하는 버릇 들이자!
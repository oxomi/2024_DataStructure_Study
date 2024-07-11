//정석
// #include <iostream>
// using namespace std;

// int main(){
//     ios::sync_with_stdio(false); //c stream 인 scanf/printf를 사용하지 않아 동기화가 필요 없을 떄 시간단축을 위해 사용
//     cin.tie(nullptr); //온라인저지에서는 출력값만 판단하므로 버퍼를 굳이 비워줄 필요 없기 때문에 시간단축을 위해 사용.
//     int a = 0, b = 0;
//     cin >> a >> b ;
    
//     int * temp = new int[a];
//     for(int i=0; i < a; i++){
//         cin >> temp[i];
//     }

//     for(int i=0; i< a; i++){
//         if(temp[i] < b){
//             cout << temp[i] << " " ;
//         }
//     }

//     delete [] temp; 

// }






//코테 권장 방식
//코딩테스트는 클린코드가 아니다!!! 무조건 빠른게 좋다.
#include <bits/stdc++.h>  //헤더 미리 다 넣어주기
using namespace std;

int a, b, temp[10005]; 

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b;
    for(int i = 0; i < a; i++) cin >> temp[i];
    for(int i = 0; i < a; i++){
        if(temp[i] < b) cout << temp[i] << " ";
    }
}





//더 빠른 방식
// #include <bits/stdc++.h>  
// using namespace std;

// int a, b, temp; //문제를 보면 사실상 배열 자체가 딱히 필요없음

// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cin >> a >> b;
//     while(a--){
//         cin >> temp;
//         if(temp < x) cout << t << " ";
//     }
// }
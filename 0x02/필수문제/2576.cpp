// //풀다가 풀이가 너무 길어지는 바람에 다지움
// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     int x;
//     int * t = new int [7];
//     for(int i = 0; i< 7; i++){
//         cin >> x;
//         t[i] = x;
//     }
        
//     }

// }


//바킹독 풀이 골져스...
#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int x, odd = 0, sum = 0, min = 100;

  for (int i = 0; i < 7; i++) {
    cin >> x; //cin은 공백 뿐만 아니라 줄바꿈문자를 기준으로 입력을 구분. 그러니 이문제에서 줄바꿈으로 입력해도 되는거임

    if (x & 1) { //LSB로 홀짝 비교
      odd += 1;
      sum += x;

      if (x < min) { //이걸 생각 못해서 개길어짐
        min = x;
      }
    }
  }

  if (odd) cout << sum << "\n" << min; //odd변수값 유무로 판별할수 있게 함
  else cout << "-1";
}
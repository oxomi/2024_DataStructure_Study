//내 힘으로 못품..ㅜㅜ
#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num;
    int cnt[10] = {}; 
    //0~8까지의 숫자가 등장한 횟수를 반환. 
  

    cin >> num;

    while(num > 0){
        int x = num % 10;
        num /= 10;
        if(x == 9) cnt[6]++;
        else cnt[x]++;

    }
    //0~8의 숫자가 등장한 횟수가 배열에 저장됨.
    //6과 9의 경우 동일한 숫자로 취급해주어야 하므로 9의 경우 6의 횟수에 일단 넣어준다.


    cnt[6] = (cnt[6]+1)/2;
    //cnt[6] 에 들어있는 6과 9의 횟수의 합을 2로 나누어 반올림 해준 것이 해당 횟수에 필요한 세트의 수이다.



    cout << *max_element(cnt, cnt+9);
    //max() : 두 수의 대소를 비교
    //max_element : 컨테이너에 있는 모든 요수들 중 최댓값을 찾음
    //cnt배열에 들어있는 수들 중 최댓값이 바로 필요한 최소한의 세트 수.


    

}

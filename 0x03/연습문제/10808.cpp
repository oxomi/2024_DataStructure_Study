#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string word;
    cin >> word;
    for(char al = 'a'; al <= 'z'; al++){
        int cnt = 0;
        for(auto c : word){ //string을 순회할 때는 주로 범위 기반 for문을 쓰는듯. 익혀두기.
            if(c == al){
                cnt++;
            }
        }
        cout << cnt << " ";
    }


}


//시간복잡도가 더 낮은 풀이
#include <bits/stdc++.h>
using namespace std;

int temp[26];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string word;
    cin >> word;

    for(auto c : word){ 
        temp[c-'a']++;
    }
    //와 어떻게 이런 생각을.... 
    //아스키코드를 이용하여 인덱스 0에 a의 횟수, 1에 b의 횟수를 저장하는 방식을 사용 함


    for(int i = 0; i < 26; i++){
        cout << temp[i] << ' ';
    }

}
#include <bits/stdc++.h>
using namespace std;

deque<int> DQ;

void pick(){
    DQ.pop_front();
}

void moveLeft(){
    int front;
    front = DQ.front();
    DQ.pop_front();
    DQ.push_back(front);
}

void moveRight(){
    int back;
    back = DQ.back();
    DQ.pop_back();
    DQ.push_front(back);
}

int main(){
    int N, M;
    cin >> N >> M;

    int cnt = 0;

    for(int i = 1; i <= N; i++){
        DQ.push_back(i);
    }

    while(M--){
        int num;
        cin >> num;


        //num이 있는 index를 먼저 찾아준다
        int index = find(DQ.begin(), DQ.end(), num) - DQ.begin();

        while(DQ.front() != num){
        //홀수일때 중간값이거나, 짝수일때 앞쪽 절반에 속한 값일 경우 왼쪽으로 밀기
            if(index <= DQ.size()/2){
                moveLeft();
                cnt++;
            }
            else{
                moveRight();
                cnt++;
            }
        }
        
        pick();
    }
    std::cout << cnt;
}
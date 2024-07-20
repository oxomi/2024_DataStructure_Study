#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K; //학생수, 방 최대인원
    bool S; //여자 0, 남자 1
    int Y; //학년
    int W[6] = {}, M[6] = {}; //성별별 학년당 명수 담을 배열
    int room = 0;

    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> S >> Y;
        if(S == 0){
            W[Y-1]++;
        }
        else if(S == 1){
            M[Y-1]++;
        }
    }

    for(int i = 0; i < 6; i++){
        room += (W[i]+K-1)/K + (M[i]+K-1)/K ; //반례 못찾아서 첨엔 실수함
    }
    cout << room;


}

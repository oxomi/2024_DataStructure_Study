//수빈이와 동생의 시작점 범위가 100000이라고 해서 무작정 배열은 100002로 설정하면 안된다
//시작점이 그 범위 안인거지 연산시 범위 밖을 벗어나는 것엔 제한이 없다.
//이 문제에선 100000 바깥으로 나가면 나갈수록 손해이므로 그냥 100002로 해도 되지만 다른 문제에선 아닐수 있다

#include <bits/stdc++.h>
using namespace std;

int N, K;
int dist[100002];

int main(){
    cin >> N >> K;
    fill(dist, dist + 100001, -1);
    queue<int> Q;
    Q.push(N);
    dist[N] = 0;

    while(!Q.empty()){
        int cur = Q.front();
        Q.pop();
        int dx[3] = {-1, 1, cur};
        for(int i = 0; i < 3; i++){
            int nx;
            if(i < 2) nx = cur + dx[i];
            else nx = 2 * cur;

            if(nx < 0 || nx >= 100002) continue; //어차피 1000002 범위 안에서 해결하는것이 가장 효율적이므로.
            if(dist[nx] >= 0) continue;
            dist[nx] = dist[cur] + 1;
            Q.push(nx);
        }
    }
    cout << dist[K];
}
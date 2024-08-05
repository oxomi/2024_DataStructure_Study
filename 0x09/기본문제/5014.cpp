#include <bits/stdc++.h>
using namespace std;

int dist[1000002];


int main(){
    fill(dist, dist + 1000002, -1);

    int F, S, G, U, D; //총 층수, 강호 위치, 스타트링크 위치, 위 버튼 한번 눌렀을때 이동하는 층수, 아래 ..
    cin >> F >> S >> G >> U >> D;

    queue<int> Q;
    Q.push(S);
    dist[S] = 0;

    while(!Q.empty()){
        int cur = Q.front();
        Q.pop();
        int dy[2] = {U, -D};
        for(int i = 0; i < 2; i++){
            int ny = cur + dy[i];
            if(ny < 1 || ny > F) continue;
            if(dist[ny] >= 0) continue; //갔던 곳 또가면 효율 떨어지니까
            Q.push(ny);
            dist[ny] = dist[cur] + 1;
        }
    }

    if(dist[G] < 0) cout << "use the stairs";
    else cout << dist[G];


}

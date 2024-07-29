#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

//입력이 빈칸으로 구분되어 있지 않는 경우 string으로 받아야 한다.
string board[102]; //이렇게 []를 써서 받으면 나중에 이차원배열처럼 board[][]를 사용할 수 있다.
int dist[102][102];
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> board[i];
    }

    //거리를 -1로 초기화하여 거리를 계산 + 갈수있는길인지의 유무 를 동시에 알 수 있게 함
    for(int  i =0; i < n; i++) fill(dist[i], dist[i]+m, -1);
    queue<pair<int, int>> Q;
    Q.push({0, 0});
    dist[0][0] = 0; //시작점이므로 거리 0 지정

    while(!Q.empty()){
        pair<int, int> cur = Q.front();
        Q.pop();
        for(int i = 0; i < 4; i++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(dist[nx][ny] >= 0 || board[nx][ny] != '1') continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }

    //cout << dist[n][m]; (n, m)에 도착하면 32번째 줄에서 큐가 비기 때문에 dist[n][m]에 값이 저장되지 않는다
    //따라서 아래와 같이 출력해주어야 한다.
    cout << dist[n-1][m-1] + 1;
}

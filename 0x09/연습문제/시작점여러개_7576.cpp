//익은 토마토는 1, 안익은 토마토는 0, 빈칸은 -1로 입력이 주어짐
//그러나, 나중에 거리를 판별하는 int dist에서는 덜익은 토마토만을 -1로 초기화해주는데
//int배열에서는 초기화를 안할 시 0으로 자동으로 채워주기 때문에 익은 토마토와 빈칸은 -1이 아니므로
//조건으로 >= 0을 넣어주면 익은토마토, 빈칸을 저절로 배제해줄수 있게 된다

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second


int board[1002][1002];
int dist[1002][1002];
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    queue<pair<int, int>> Q; //큐를 미리 선언
    for(int i = 0; i < n; i++){
        for(int  j = 0; j < m; j++){
            cin >> board[i][j];
            if(board[i][j] == 1) Q.push({i, j}); //큐에 시작점이 될 수 있는 입력값 1의 좌표를 미리 다 넣어둔다.
            if(board[i][j] == 0) dist[i][j] = -1; //덜익은 토마토만을 -1로 초기화 -> 거리측정과 동시에 익은 토마토, 빈칸을 솎아낼 수 있다
        }
    }

    while(!Q.empty()){
        pair<int, int> cur = Q.front(); //큐에 미리 담긴 여러개의 시작점을 기준으로 상하좌우 한번씩 돌고 그 상하좌우들에 대해서 또 도니까 결국 다 돌수있게 된다
        Q.pop();
        for(int i = 0; i < 4; i++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(dist[nx][ny] >= 0) continue; //원래 익은 토마토 혹은 빈같이어서 0인 경우와 덜익은토마토가 익은토마토로 바뀌어 거리가 0 이상이 된 경우를 배제해주는 것
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(dist[i][j] == -1){
                cout << -1;
                return 0;
            }
            ans = max(ans, dist[i][j]);
        }
    }

    cout << ans; //입력될때 모든 토마토가 익은상태이면 당연히 dist값은 다 0이니 0이 충족될 것이므로 모든 조건에 부합

}

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int T, M, N, K;
int board[52][52];
bool vis[52][52];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void reset() {
    for(int i = 0; i < 52; i++){
        fill(board[i], board[i] + 52, 0);
        fill(vis[i], vis[i] + 52, 0);
    }
}

int main(){     
    cin >> T;

    while(T--){
        cin >> M >> N >> K;

        // 보드에 배추 위치 넣기
        for(int i = 0; i < K; i++){
            int x, y;
            cin >> x >> y;
            board[y][x] = 1; // (x, y)은 (열, 행)
        }

        // 지렁이 개수 구하기
        int num = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(board[i][j] != 1 || vis[i][j]) continue;
                num++;
                queue<pair<int, int>> Q;
                vis[i][j] = 1;
                Q.push({i, j});

                // 각 군락별 BFS 돌리기
                while(!Q.empty()){
                    pair<int, int> cur = Q.front();
                    Q.pop();
                    for(int k = 0; k < 4; k++){
                        int nx = cur.X + dx[k];
                        int ny = cur.Y + dy[k];
                        if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue; // 범위를 먼저 체크
                        if(board[nx][ny] != 1 || vis[nx][ny]) continue;
                        Q.push({nx, ny});
                        vis[nx][ny] = 1;
                    }
                }
            }
        }
        cout << num << '\n';
        reset();
    }
    return 0;
}

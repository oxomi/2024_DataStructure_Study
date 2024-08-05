#include <bits/stdc++.h>
using namespace std;

int board[103][103][103];
int dist[103][103][103];
int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int main(){
    int M, N, H; //가로, 세로, 높이
    cin >> M >> N >> H;
    queue<tuple<int, int, int>> Q; //세개짜리 큐는 튜플 사용

    for(int h = 0; h < H; h++){
        for(int n = 0; n < N; n++){
            for(int m = 0; m < M; m++){
                cin >> board[n][m][h]; //행, 열, 높이
                //시작점 설정
                if(board[n][m][h] == 1) Q.push({n, m, h});
                if(board[n][m][h] == 0) dist[n][m][h] = -1; //덜익은 토마토만 거리를 -1로 만들어주기
            }
        }
    }

    while(!Q.empty()){
        tuple<int, int, int> cur = Q.front();
        Q.pop();
        //튜플의 사용법
        int curX, curY, curZ;
        tie(curX, curY, curZ) = cur;
        for(int i = 0; i < 6; i++){
            int nx = curX + dx[i];
            int ny = curY + dy[i];
            int nz = curZ + dz[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M || nz < 0 || nz >= H) continue;
            if (dist[nx][ny][nz] >= 0) continue;
            dist[nx][ny][nz] = dist[curX][curY][curZ] + 1;
            Q.push({nx, ny, nz});
        }
    }

    int ans = 0;
    for(int h = 0; h < H; h++){
        for(int n = 0; n < N; n++){
            for(int m = 0; m < M; m++){
               if(dist[n][m][h] == -1){
                cout << -1;
                return 0;
               }

               ans = max(ans, dist[n][m][h]);
            }
        }
    }

    cout << ans;
    return 0;

}
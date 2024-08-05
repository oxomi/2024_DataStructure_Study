#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[102][102];
int vis[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    int N;
    cin >> N;

    int max_h = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
            max_h = max(max_h, board[i][j]);
        }
    }

    int max_num = 0;

    for(int h = 0; h <= max_h; h++){
        // vis 배열 초기화하는 다른 방법이라고하는군요
        memset(vis, 0, sizeof(vis));

        int num = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(board[i][j] <= h || vis[i][j] == 1) continue;
                num++;
                queue<pair<int, int>> Q;
                vis[i][j] = 1;
                Q.push({i, j});

                while(!Q.empty()){
                    pair<int, int> cur = Q.front();
                    Q.pop();
                    for(int k = 0; k < 4; k++){
                        int nx = cur.X + dx[k];
                        int ny = cur.Y + dy[k];
                        if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                        if(vis[nx][ny] == 1 || board[nx][ny] <= h) continue;
                        vis[nx][ny] = 1;
                        Q.push({nx, ny});
                    }
                }
            }
        }
        max_num = max(max_num, num);
    }

    cout << max_num << endl;
    return 0;
}

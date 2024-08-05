#include <bits/stdc++.h>
using namespace std;
#define X first 
#define Y second

string board[102];
char color[3] = {'R', 'G', 'B'};
bool vis[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};




int main(){
    int N;
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> board[i];
    }

    int num_dif = 0;
    int num_same = 0;

    //적록색약이 아닌 사람이 봤을때
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N;  j++){
            queue<pair<int, int>> Q;
            for(int c = 0; c < 3; c++){
                if(board[i][j] != color[c] || vis[i][j] == 1) continue;
                num_dif++;
                Q.push({i, j});
                vis[i][j] = 1;

                while(!Q.empty()){
                    pair<int, int> cur = Q.front();
                    Q.pop();
                    for(int i = 0; i < 4; i++){
                        int nx = cur.X + dx[i];
                        int ny = cur.Y + dy[i];
                        if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                        if(board[nx][ny] != color[c] || vis[nx][ny] == 1) continue;
                        Q.push({nx, ny});
                        vis[nx][ny] = 1;
                    }
                }    
            }
        }
    }


    //방문여부 초기화
    for(int i = 0; i < N; i++){
        fill(vis[i], vis[i] + N, 0);
    }


    //적록색약인 사람이 봤을 때
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N;  j++){
            queue<pair<int, int>> Q;
            if(vis[i][j] == 1) continue;
            if(board[i][j] == 'R' || board[i][j] == 'G'){
                num_same++;
                Q.push({i, j});
                vis[i][j] = 1;

                while(!Q.empty()){
                    pair<int, int> cur = Q.front();
                    Q.pop();
                    for(int i = 0; i < 4; i++){
                        int nx = cur.X + dx[i];
                        int ny = cur.Y + dy[i];
                        if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                        if(board[nx][ny] == 'B' || vis[nx][ny] == 1) continue;
                        Q.push({nx, ny});
                        vis[nx][ny] = 1;
                    }
                }
            }

            if(board[i][j] == 'B' || vis[i][j] != 1){
                num_same++;
                Q.push({i, j});
                vis[i][j] = 1;

                while(!Q.empty()){
                    pair<int, int> cur = Q.front();
                    Q.pop();
                    for(int i = 0; i < 4; i++){
                        int nx = cur.X + dx[i];
                        int ny = cur.Y + dy[i];
                        if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                        if(board[nx][ny] != 'B' || vis[nx][ny] == 1) continue;
                        Q.push({nx, ny});
                        vis[nx][ny] = 1;
                    }
                }
            }
    
        }
    }

    cout << num_dif << " " << num_same;
}





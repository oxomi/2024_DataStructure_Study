#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int board[102][102];
int vis[102][102];


int main(){
    int M, N, K;
    cin >> M >> N >> K;


    int x, y, xx, yy;
    for(int i = 0; i < K; i++){
        cin >> x >> y >> xx >> yy;
        for(int j = x; j < xx; j++){
            for(int k = y; k < yy; k++){
                board[j][k] = 1;
            }
        }
    }

    //0인 칸 중에서 시작점 잡기
    int num = 0;
    vector<int> sizes;
    queue<pair<int, int>> Q;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(board[i][j] != 0 || vis[i][j] ==  1) continue;
            num++;
            vis[i][j] = 1; 
            Q.push({i, j});

            int size = 0;
            while(!Q.empty()){
                pair<int, int> cur = Q.front();
                Q.pop();
                size++;
                for(int k = 0; k < 4; k++){
                    int nx = cur.X + dx[k];
                    int ny = cur.Y + dy[k];
                    if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                    if(vis[nx][ny] == 1 || board[nx][ny] != 0) continue;
                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
            sizes.push_back(size);
        }
    }

    //오름차순으로 사이즈 나열
    sort(sizes.begin(), sizes.end());
    cout << num << '\n';
    for(int s : sizes){
        cout << s << ' ';
    }



}
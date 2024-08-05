#include <bits/stdc++.h>
using namespace std;
#define X first 
#define Y second

string board[1002];
int dist1[1002][1002]; //불이 움직이는 시간
int dist2[1002][1002]; //상근이가 움직이는 시간
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    int tk, w, h;
    cin >> tk;

    while(tk--){
        cin >> w >> h;

        for(int i = 0; i < h; i++){
            fill(dist1[i], dist1[i] + w, -1);
            fill(dist2[i], dist2[i] + w, -1);
        }

        for(int i = 0; i < h; i++){
            cin >> board[i];
        }

        //불과 상근이의 시작점 넣기
        queue<pair<int, int>> Q1;
        queue<pair<int, int>> Q2;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(board[i][j] == '*'){
                    Q1.push({i, j});
                    dist1[i][j] = 0;
                }
                if(board[i][j] == '@'){
                    Q2.push({i, j});
                    dist2[i][j] = 0;
                }
            }
        }

        //불의 bfs
        while(!Q1.empty()){
            pair<int, int> cur1 = Q1.front();
            Q1.pop();
            for(int i = 0; i < 4; i++){
                int nx = cur1.X + dx[i];
                int ny = cur1.Y + dy[i];
                if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if(dist1[nx][ny] >= 0 || board[nx][ny] == '#') continue;
                dist1[nx][ny] = dist1[cur1.X][cur1.Y] + 1;
                Q1.push({nx, ny});
            }
        }

        //상근이의 bfs
        bool flag = false;
        while(!Q2.empty()){ 
            pair<int, int> cur2 = Q2.front();
            Q2.pop();

            for(int i = 0; i < 4; i++){
                int nx = cur2.X + dx[i];
                int ny = cur2.Y + dy[i];
                if(nx < 0 || nx >= h || ny < 0 || ny >= w){
                    cout << dist2[cur2.X][cur2.Y] + 1 << '\n';
                    flag = true;
                    break;
                }
                if(dist2[nx][ny] >= 0 || board[nx][ny] == '#') continue;
                if(dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur2.X][cur2.Y] + 1) continue; 
                
                dist2[nx][ny] = dist2[cur2.X][cur2.Y] + 1;
                Q2.push({nx, ny});
            }
        }

        if(flag == false) cout << "IMPOSSIBLE" << '\n';
    }
}



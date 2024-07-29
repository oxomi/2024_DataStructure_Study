//불과 지훈이의 BFS를 따로 구한다
//먼저 지훈이의 이동경로 배제하고 각 칸에 불이 전파되는 시간을 구한다.
//그다음 지훈이가 특정 칸을 방문하는 시간x를 구하고 x가 불이 전파되는 시간과 같거나 느리면 continue 해주면 된다
//!! 그러나 만약 불과 물이었다면 두 전파가 서로에게 영향을 미치므로 다르게 생각해야 한다(18809-백트래킹을 추가로 알아야 함)

#include <bits/stdc++.h>
using namespace std;
#define X first 
#define Y second

string board[1002];
int n, m;
int dist1[1002][1002]; //불의 전파시간
int dist2[1002][1002]; //지훈이의 이동시간
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        fill(dist1[i], dist1[i] + m, -1);
        fill(dist2[i], dist2[i] + m, -1);
    }

    for(int i = 0; i < n; i++){
        cin >> board[i];
    }


    //불과 지훈이 시작점 큐에 넣기
    queue<pair<int, int>> Q1; //불에 대한 큐
    queue<pair<int, int>> Q2; //지훈이에 대한 큐
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == 'F'){
                Q1.push({i, j});
                dist1[i][j] = 0;
            }
            if(board[i][j] == 'J'){
                Q2.push({i, j});
                dist2[i][j] = 0;
            }
        }
    }


    //불에 대한 BFS 돌리기
    while(!Q1.empty()){
        pair<int, int> cur1 = Q1.front();
        Q1.pop();
        for(int i = 0; i < 4; i++){
            int nx = cur1.X + dx[i];
            int ny = cur1.Y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(dist1[nx][ny] >= 0 || board[nx][ny] == '#') continue;
            dist1[nx][ny] = dist1[cur1.X][cur1.Y] + 1;
            Q1.push({nx, ny});
            
        }
    }


    //지훈이에 대한 BFS 돌리기
    while(!Q2.empty()){
        pair<int, int> cur2 = Q2.front();
        Q2.pop();

        for(int i = 0; i < 4; i++){
            int nx = cur2.X + dx[i];
            int ny = cur2.Y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m){
                //벽으로 둘러싸이지 않은 곳을 통해 행렬의 범위 밖으로 나갔다는 뜻이므로 탈출 성공
                //탈출에 걸리는 시간이 짧은 순서대로 큐에 저장될것이기 때문에 최소시간을 구하고자 할 때는 
                //최초로 탈출에 성공했을때 바로 출력하면 됨
                cout << dist2[cur2.X][cur2.Y] + 1;
                return 0;
            }
            if(dist2[nx][ny] >= 0 || board[nx][ny] == '#') continue;
            if(dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur2.X][cur2.Y] + 1) continue; //윗줄과 달리 dist2[nx][ny] 로 하면 틀림. 값이 안들어있는부분이니까~
            dist2[nx][ny] = dist2[cur2.X][cur2.Y] + 1;
            Q2.push({nx, ny});
        }
    }
    cout << "IMPOSSIBLE";
}
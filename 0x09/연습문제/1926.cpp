#include <bits/stdc++.h>
using namespace std;
#define X first //pair에서 두 좌표를 나타내는 first, second를 줄이기 위해 사용
#define Y second 

int board[502][502]; //그림(파란칸) 위치값 //2차원배열
bool vis[502][502]; //방문여부
int n,  m; //도화지 크기
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }

    int num = 0, max_size = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            //기본예제에서 무조건 (0,0)으로 시작하는 것과 다르게 
            //행열 전체 요소 돌아가면서 가능 여부 확인 후 시작점 설정
            if(vis[i][j] == 1 || board[i][j] != 1) continue;
            num++;
            queue<pair<int, int> > Q;
            vis[i][j] = 1; 
            Q.push({i, j});

            int size = 0;
            while(!Q.empty()){
                size++;
                pair<int, int> cur = Q.front();
                Q.pop();
                for(int k = 0; k < 4; k++){
                    int nx = cur.X + dx[k];
                    int ny = cur.Y + dy[k];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(vis[nx][ny] == 1 || board[nx][ny] != 1) continue;
                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
            max_size = max(max_size, size);

        }
    }

    cout << num << '\n' << max_size;


}


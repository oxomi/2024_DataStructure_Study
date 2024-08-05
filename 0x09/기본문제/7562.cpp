#include <bits/stdc++.h>
using namespace std;
#define X first 
#define Y second

int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dist[302][302];


int main(){
    int tk, I;
    int x, y, xx, yy; //시작점, 도착점
    cin >> tk;

    //테케
    while(tk--){
        //dist 초기화
        for(int i = 0; i < 302; i++){
            fill(dist[i], dist[i] + 302, -1);
        }

        queue<pair<int, int>> Q;
        cin >> I;

        cin >> x >> y;
        Q.push({x, y});
        dist[x][y] = 0;

        cin >> xx >> yy;
        
        while(!Q.empty()){
            pair<int, int> cur = Q.front();
            Q.pop();
            for(int i = 0; i < 8; i++){
                int nx = cur.X + dx[i];
                int ny = cur.Y + dy[i];
                if(nx < 0 || nx >= I || ny < 0 || ny >= I) continue;
                if(dist[nx][ny] >= 0) continue;
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                Q.push({nx, ny});
            }
        }
        cout << dist[xx][yy] << '\n';
    }
}
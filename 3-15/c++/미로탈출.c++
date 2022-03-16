#include<iostream>
#include <vector>
#include <queue>
#include<algorithm>

// DFS
using namespace std;

int n , m;

queue<pair<int,int>> q;
int picture[101][101];
bool visited[101][101];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void bfs(int y, int x){
    
    visited[y][x] = true;
    q.push({y, x});
    
    while (!q.empty()) {

        y = q.front().first;
        x = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;

            if (!visited[ny][nx] && picture[ny][nx] != 0) {
                visited[ny][nx] = true;
                picture[ny][nx] = picture[y][x] + 1;
                q.push({ny, nx});
            }
        }
    }
    printf("%d\n", picture[n - 1][m - 1]);
}
void solution() {
    scanf("%d %d", &n, &m);

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            int a ;
            scanf("%1d", &a);
            picture[y][x] = a;
        }
    }
    bfs(0, 0);
}


/*
6 5
1 1 0 1 1
0 1 1 0 0
0 0 0 0 1
1 0 1 1 1
0 0 1 1 1
0 0 1 1 1
 */
int main(){
    solution();
}
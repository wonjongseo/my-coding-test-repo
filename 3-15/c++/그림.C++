#include<iostream>
#include <vector>
#include <queue>
#include<algorithm>

// DFS
using namespace std;

int n , m;

int picture[501][501];
bool visited[501][501];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
int Count = 0;
int Result =0;

void dfs(int y, int x){

    visited[y][x] = 1;
    Count++;

    for (int dir = 0; dir < 4; dir++) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if(nx < 0 || ny < 0 || nx >= m || ny>= n) continue;

        if (visited[ny][nx] == 0 && picture[ny][nx] == 1) {
            dfs(ny, nx);
        }
    }
}
void solution() {
    scanf("%d %d", &n, &m);

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            scanf("%d", &picture[y][x]);
        }
    }
    int cnt = 0;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (visited[y][x] ==0 && picture[y][x] == 1) {
                Count = 0;
                dfs(y, x);
                cnt++;
                Result = max(Result, Count);
            }
        }
    }

    printf("%d\n%d", cnt, Result);
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
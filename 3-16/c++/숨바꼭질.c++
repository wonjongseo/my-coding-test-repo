#include <queue>
#include<algorithm>
#include <iostream>
using namespace std;

int T ;
int N , M;
int map[51][51];
bool visited[51][51];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int K;

void dfs(int x, int y){
    visited[y][x] = 1;

    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx < 0 || ny < 0 || nx >= M  || ny >= N) continue;

        if (visited[ny][nx] == 0 && map[ny][nx] == 1) {
            dfs(nx, ny);
        }
    }
}
int main(){
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);

    cin >> T;
    while (T--) {
        cin >> M >> N >> K;

        for (int i = 0; i < K; i++) {
            int x, y;
            cin >> x >> y;
            map[y][x] = 1;
        }

        int cnt = 0;
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                if (visited[y][x] == 0 && map[y][x] == 1) {
                    dfs(x, y);
                    cnt++;
                }
            }
        }
        printf("%d\n", cnt);

        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                map[y][x] = 0;
                visited[y][x] = 0;
            }
        }
    }
}
/*
1
10 8 17
0 0
1 0
1 1
4 2
4 3
4 5
2 4
3 4
7 4
8 4
9 4
7 5
8 5
9 5
7 6
8 6
9 6
10 10 1
5 5
 */
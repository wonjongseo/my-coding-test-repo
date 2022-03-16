#include <queue>
#include<algorithm>
#include <iostream>
using namespace std;

int N ,M , H;

int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};
int visited[103][103][103];
int map[103][103][103];

queue<tuple<int, int, int>> Q;

int main(){
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);

    cin >> M >> N >> H;

    for (int z = 0; z < H; z++) {
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                int tmp;
                cin >> tmp;
                map[z][y][x] = tmp;
                if (tmp == 1) Q.push({x, y, z});
                if(tmp == 0) visited[z][y][x] = -1;
            }
        }
    }

    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        int x, y, z;
        tie(x, y, z) = cur;

        for (int dir = 0; dir < 6; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int nz = z + dz[dir];

            if(nx < 0 || ny < 0 || nz < 0 || nx >= M || ny >= N || nz >=H) continue;

            if(visited[nz][ny][nx] >= 0) continue;

            visited[nz][ny][nx] = visited[z][y][x] + 1;
            Q.push({nx, ny, nz});
        }
    }
    int result = 0;
    for (int z = 0; z < H; z++) {
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                if (visited[z][y][x] == -1) {
                    cout << "-1";
                    return 0;
                }
                result = max(result, visited[z][y][x]);
            }
        }
    }
    cout << result;
    return 0;


}
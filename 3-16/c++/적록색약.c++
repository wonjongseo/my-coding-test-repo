
#include <queue>
#include<algorithm>
#include <iostream>
using namespace std;

int N ;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

bool visited[101][101];
queue<pair<int,int>> Q;

void bfs(int x, int y, char color, char map[101][101]) {

    visited[y][x] = true;
    Q.push({x, y});

    while (!Q.empty()) {
        x = Q.front().first;
        y = Q.front().second;
        Q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= N || ny >= N) {
                continue;
            }

            if (!visited[ny][nx] && map[ny][nx] == color) {
                visited[ny][nx] = true;
                Q.push({nx, ny});
            }
        }
    }

}

int main(){

    char map[101][101];
    char map2[101][101];

    cin >> N;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> map[y][x];
            if (map[y][x] == 'G') {
                map2[y][x] = 'R';
            }
            else{
                map2[y][x] = map[y][x];
            }

        }
    }

    int count =0;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if(!visited[y][x]){
                bfs(x,y ,map[y][x], map);
                count++;
            }
        }
    }
    cout << count << "\n";

    count = 0;
    for (int i = 0; i < N; i++) {
        fill(visited[i], visited[i] + 101, false);
    }
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N; j++) {
//            printf("%c", map2[i][j],map);
//        }
//        printf("\n");
//    }
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if(!visited[y][x]){
                bfs(x,y ,map2[y][x],map2);
                count++;
            }
        }
    }
    cout << count << "\n";
}
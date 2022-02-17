#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int graph[8][8];
int temp[8][8];

int N, M;


int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int score = 0;

int result = 0;

void virus(int x, int y){

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny <= 0 || nx>= N ||  ny >= M) continue;

        if (temp[nx][ny] ==0) {
            temp[nx][ny] = 2;

            virus(nx, ny);
        }

    }

}

int getScore() {
    int score = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (temp[i][j] == 0) {
                score += 1;
            }
        }
    }
    return score;
}

void dfs(int count){
    if (count == 3) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                temp[i][j] = graph[i][j];
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (temp[i][j] == 2) {
                    virus(i, j);
                }
            }
        }
        result = max(result, getScore());
        return;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (graph[i][j] == 0) {
                graph[i][j] = 1;
                count++;
                dfs(count);
                count--;
                graph[i][j] = 0;

            }
        }
    }
}

int main() {

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> graph[i][j];
        }
    }

    dfs(0);

    cout << result << endl;
}

//01101010
/*
4 6
 0 0 0 0 0 0
 1 0 0 0 0 2
 1 1 1 0 0 2
 0 0 0 0 0 2
 */
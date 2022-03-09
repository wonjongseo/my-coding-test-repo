#include <queue>
#include <vector>
#include <iostream>
#define INF 1e9
using namespace std;

int N , M;
int arr[8][8];
int temp[8][8];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int result ;

void virus(int x, int y){
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
            if (temp[nx][ny] == 0) {
                temp[nx][ny] = 2;
                virus(nx, ny);
            }
        }
    }
}

int getScore(){
    int s = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (temp[i][j] == 0) {
                s++;
            }
        }
    }
    return s;
}
void dfs(int count){
    if (count == 3) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                temp[i][j] = arr[i][j];
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
            if (arr[i][j] == 0) {
                arr[i][j] = 1;
                count += 1;
                dfs(count);
                count -= 1;
                arr[i][j] = 0;
             }
        }
    }
}
int main(){
    cin >> N  >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }
    dfs(0);


    cout << result;


}
/*
 7 7
 2 0 0 0 1 1 0
 0 0 1 0 1 2 0
 0 1 1 0 1 0 0
 0 1 0 0 0 0 0
 0 0 0 0 0 1 1
 0 1 0 0 0 0 0
 0 1 0 0 0 0 0
 */
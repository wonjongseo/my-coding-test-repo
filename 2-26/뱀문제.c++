#include <queue>
#include <vector>
#include <iostream>

using namespace std;

int n, k , l;

int arr[101][101];
vector<pair<int,char>>  info;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int truen(int direction, char c){
    if(c== 'L') direction = direction == 0 ? 3 : direction - 1;
    else direction = (direction + 1) % 4;
    return direction;
}

int simulate(){
    int x = 1, y = 1;
    arr[x][y] = 2;
    int direction = 0;
    int time = 0;
    int index = 0;
    queue<pair<int, int>> queue;
    queue.push({x, y});

    while (true) {
        int nx = x + dx[direction];
        int ny = y + dy[direction];
        if( 1<= nx && nx <= n && 1 <=ny && ny <= n && arr[nx][ny] != 2){
            if (arr[nx][ny] == 0) {
                arr[nx][ny] = 2;
                queue.push({nx, ny});
                int px = queue.front().first;
                int py = queue.front().second;
                queue.pop();
                arr[px][py] = 0;
            }
            if (arr[nx][ny] == 1) {
                arr[nx][ny] = 2;
                queue.push({nx, ny});
            }
        }
        else {
            time += 1;
            break;
        }

        x = nx;
        y = ny;
        time += 1;

        if (index < l && time == info[index].first) {
            direction = truen(direction, info[index].second);
            index += 1;
        }
    }
    return time;

}


int main(){
    cin >> n >> k;

    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;
    }

    cin >> l;

    for (int i = 0; i < l; i++) {
        int x;
        char c;

        cin >> x >> c;

        info.push_back({x, c});
    }

    cout << simulate() << endl;

}

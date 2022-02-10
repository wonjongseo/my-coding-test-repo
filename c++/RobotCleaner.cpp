#include <iostream>

using namespace std;

bool visit[51][51];
int rooms[51][51];
int n ,m  , x, y, direction;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0 , 1, 0 ,-1};

void trun_left(){
    direction--;

    if(direction == -1) direction = 3;
}

int main(){
    cin >> n >> m ;
    cin >> x >> y >> direction;

    for(int i = 0 ; i < n  ;i++){
        for(int j = 0 ; j< m ;j++){
            cin >> rooms[i][j];
        }
    }
    int cnt = 1;
    int turn_time = 0;
    visit[x][y] = true;

    while(true){
        trun_left();
        int nx = x + dx[direction];
        int ny = y + dy[direction];

        if(visit[nx][ny]== false && rooms[nx][ny] == 0){
            x = nx;
            y = ny;
            visit[x][y] = true;
            cnt++;
            turn_time = 0;
            continue;
        }
        else turn_time ++;

        if(turn_time == 4){

            nx = x - dx[direction];
            ny = y - dy[direction];

            if(rooms[nx][ny] == 0){
                x = nx;
                y = ny;
                turn_time = 0;
            }
            else break;


        }
    }

    cout << cnt;




}
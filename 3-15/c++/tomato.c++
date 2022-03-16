#include <iostream>
#include <queue>
using namespace std;


int board[1002][1002];
int dist[1002][1002];

int n, m;
int dx[4]= {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;

    queue<pair<int,int> > Q;
    for(int i = 0 ; i< n ; i++){
        for(int j = 0 ; j< m ;j++){
            cin >> board[i][j];
                if(board[i][j] == 1){
        Q.push({i,j});
                }
        
        }
    }
}
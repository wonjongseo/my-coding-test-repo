#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    cin.ignore();

    string plans;

    int x = 1, y= 1;
    int dx[] = { 0,0,-1, 1};
    int dy[] = {-1 ,1 , 0,0};
    string move_types = "LRUD";

    getline(cin, plans);

    for( int i = 0 ; i< plans.size() ; i++){
        char plan = plans[i];
        int nx = 0 , ny = 0;
        for(int j = 0 ; j< 4 ; j++){
            if(plan == move_types[j]){
                nx = x+ dx[j];
                ny= y + dy[j];
            }
        }
        if( nx < 1 || ny < 1 || nx > n || ny > n) continue;

        x =nx;
        y = ny;
    }

    cout << x << " " << y << endl;
}
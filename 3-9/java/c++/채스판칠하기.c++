#include <queue>
#include <vector>
#include <iostream>
#include <string>
#define INF 1e9
using namespace std;
int N, M;

int main(){
    cin>> N >> M;
    char map[50][51];
    for (int i = 0; i < N; i++) {
        scanf("%s", map[i]);
    }
    int result = 1e9;


    for (int x = 0; x < N-7; x++) {
        for (int y = 0; y < M-7; y++) {
            int countW = 0;
            int countB = 0;
            for (int i = x; i < x + 8; i++) {
                for (int j =y; j < y + 8; j++) {
                        if( (i+j)% 2== 0) {
                            if (map[i][j] == 'B')
                                countW++;

                            else countB++;
                        }else{
                            if (map[i][j] == 'B')
                                countB++;

                            else countW++;
                        }
                }

                }
                result = min(result, countW);
                result = min(result, countB);

            }

        }

    cout << result;
}

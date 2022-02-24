#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    int map[501][501];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i+1; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <=i; j++) {
            int up_left, up;

            if (j == 0) {
                up_left = 0;
            } else {
                up_left = map[i - 1][j - 1];
            }

            up = map[i - 1][j];

            map[i][j] = map[i][j] + max(up, up_left);
        }
    }

    int result = map[n - 1][0];
    for (int i = 1; i < n; i++) {

        result = max(result, map[n - 1][i]);
    }

    printf("%d\n", result);
}



/*
 5
 7
 3 8
 8 1 0
 2 7 4 4
 4 5 2 6 5
 */
#include <stdio.h>
#include <algorithm>
using namespace std;

int n , m , tr;
int main(){
    scanf("%d", &tr);
    printf("\n");
    int map[10][10];

    while (tr--) {
        scanf("%d %d", &n, &m);
        printf("\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &map[i][j]);
            }
        }


        int result = 0;


        for (int j = 1; j < m; j++) {
            for (int i = 0; i < n; i++) {
                int up_left, down_left, left;
                if (i == 0) {
                    up_left = 0;
                }
                else {
                    up_left = map[i - 1][j - 1];
                }

                if (i == n - 1) {
                    down_left = 0;
                }
                else{
                    down_left = map[i + 1][j - 1];
                }

                left = map[i][j - 1];

                int max_value = max(up_left, down_left);
                max_value = max(max_value, left);

                map[i][j] = map[i][j] + max_value;
            }
        }

        result = map[0][n - 1];
        for (int i = 1; i < n; i++) {
            result = max(result, map[i][m-1]);
//            printf("%d\n", result);
        }

        printf("%d", result);

    }

}


/*
 2
 3 4
 1 3 3 2 2 1 4 1 0 6 4 7
 4 4
 1 3 1 5 2 2 4 1 5 0 2 3 0 6 1 2
 */
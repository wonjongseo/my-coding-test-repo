#include <stdio.h>
#include <algorithm>
#define INF 1e9
using namespace std;

int n,m ;
int graph[101][101];

int main(){
    scanf("%d %d", &n, &m);

    for (int i = 1; i <=n; i++) {
        for (int j =1; j <= n; j++) {
            if (i == j) {
                graph[i][j] =0;
            }
            else{
                graph[i][j] = INF;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if (graph[a][b] > c) {
            graph[a][b] = c;
//            printf("%d ", graph[a][b]);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k<= n; k++) {
                graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
            }
        }
    }

    for(int i = 1 ; i<= n ;i++){
        for (int j = 1; j <= n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

}
/*
5 14
 1 2 2
 1 3 3
 1 4 1
 1 5 10
 2 4 2
 3 4 1
 3 5 1
 4 5 3
 3 5 10
 3 1 8
 1 4 2
 5 1 7
 3 4 2
 5 2 4
 */
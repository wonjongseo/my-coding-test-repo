#include<iostream>
#include <vector>

#include<algorithm>

using namespace std;
int map[9];


void solution() {
     int n , m;
    scanf("%d %d", &n, &m);

    if (n > m) {
        int  tmp = n;
        n = m ;
        m = tmp;
    }

    for (int i = n; i >= 2; i--) {
        if (n % i == 0 && m % i == 0) {
            printf("%d\n%d\n", i, n * m / i);
            return;
        }
    }
    printf("1\n%d\n", n* m);

}


int main(){
    solution();

    return 0;

}
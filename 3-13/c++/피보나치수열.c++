#include<iostream>
#include<algorithm>

using namespace std;
int d[21];
void solution(int n) {
    d[1] = d[2] = 1;
    for (int i = 3; i <= n; i++) {
        d[i] = d[i - 1] + d[i - 2];
    }

    printf("%d\n", d[n]);
}


int main(){
    int n;
    scanf("%d", &n);
    solution(n);

    return 0;

}
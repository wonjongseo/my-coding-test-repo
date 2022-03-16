#include<iostream>
#include <vector>

#include<algorithm>

using namespace std;
int map[9];

bool isPrime(int num){
    if(num == 1) return false;
    for (int i = 2; i < num; i++) {
        if(num % i == 0) return false;
    }
    return true;
}

void solution() {

    int n , m;

    scanf("%d %d", &n, &m);
    int min = 0;
    int total = 0;
    for (int i = n; i <= m; i++) {
        if (isPrime(i)) {
            if (min == 0) {
                min = i;
            }
            total += i;
        }
    }
    if(min != 0)
        printf("%d\n%d", total, min);
    else
        printf("-1");
}

int main(){
    solution();

    return 0;

}
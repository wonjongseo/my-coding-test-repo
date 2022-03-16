#include<iostream>
#include<algorithm>

using namespace std;
int T;
void solution() {
    int n;
    scanf("%d", &n);
    int max = -1e6;
    int min = 1e6;
    for (int i = 0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);
        if (tmp > max) {
            max = tmp;
        }
        if (tmp < min) {
            min = tmp;
        }
    }

    printf("%d %d\n", min, max);
}


int main(){

        solution();

    return 0;

}
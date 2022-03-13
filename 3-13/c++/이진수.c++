#include<iostream>
#include<algorithm>

using namespace std;
int T;
void solution() {
    int count = 0;
    int n;
    scanf("%d", &n);
    while (n >= 1) {
        int tmp = n % 2;
        if (tmp == 1) {
            printf("%d ", count);
        }
        n = n / 2;
        count++;
    }
    printf("\n");
}


int main(){

    scanf("%d",&T);
    while(T--){
        solution();
    }

    return 0;

}
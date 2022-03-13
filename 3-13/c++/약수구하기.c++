#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int q,p;
    scanf("%d %d", &q, &p);

    int count = 0;
    int result = 0;
    for (int i = 1; i <= q; i++) {
        if (q % i == 0) {
            count++;
            if (count == p) {
                result = i;
                break;

            }
        }
    }

    printf("%d\n", result);
}
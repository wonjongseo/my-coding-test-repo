#include<iostream>
#include <vector>

#include<algorithm>

using namespace std;
int map[9];


void solution() {
    int sum = 0;
    for (int i = 0; i < 9; i++) {
        scanf("%d", map + i);
        sum += map[i];
    }

    sort(map, map + 9);

    for (int i = 0; i < 9-1; i++) {
        for (int j = i + 1; j < 9; j++) {
            if (sum - map[i] - map[j] == 100) {
                for (int k = 0; k < 9; k++) {
                    if(k == i || k ==j) continue;
                    printf("%d\n", map[k]);
                }
                return;

            }
        }
    }
}


int main(){
    solution();

    return 0;

}
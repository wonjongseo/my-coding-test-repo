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

int solution() {
    int n;
    int arr[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (isPrime(arr[i])) {
            count++;
        }
    }
    return count;
}


int main(){
    int a = solution();
    printf("%d\n", a);
    return 0;

}
#include <string>
#include <iostream>
using namespace std;

int N;
int numbers[101];

int max_result = -1e9;
int min_result = 1e9;

int add, sub, mul, divi;

void dfs(int i, int now){
    if (i == N) {
        min_result = min(min_result, now);
        max_result = max(max_result, now);
    }
    else{
        if (add > 0) {
            add -= 1;
            dfs(i + 1, now + numbers[i]);
            add += 1;
        }
        if (sub > 0) {
            sub -= 1;
            dfs(i + 1, now - numbers[i]);
            sub += 1;
        }
        if (mul> 0) {
            mul -= 1;
            dfs(i + 1, now * numbers[i]);
            mul += 1;
        }
        if (divi > 0) {
            divi -= 1;
            dfs(i + 1, now / numbers[i]);
            divi += 1;
        }
    }
}

int main(){

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }

    cin >> add >> sub >> mul >> divi;
    dfs(1, numbers[0]);

    cout << max_result << endl;
    cout << min_result << endl;

}
/*
3
3 4 5
1 0 1 0
 */
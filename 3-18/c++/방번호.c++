#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace  std;

int Sets[10] = {0, 1, 2, 3, 4, 6, 7, 8, 9};

int main(){
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    int N;
    cin >> N;


    int freq[10] = {0};
    int result = 1;

    while (N > 0) {
        int tmp = N % 10;
        if (tmp == 9 || tmp == 6) {
            int Abs = freq[6] - freq[9];
            if (Abs > 0 ) {
                tmp = 9;
                freq[tmp]++;
            }
            else{
                tmp = 6;
                freq[tmp]++;
            }
        }
        else
            freq[tmp]++;
        result = max(result, freq[tmp]);
        N /=10;
    }
    printf("%d", result);
}


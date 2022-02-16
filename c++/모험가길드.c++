// page 311
// 모험가의 길드
// 2.16 , 10.50
// Grid Algorithm
#include <iostream>
#include <algorithm>
#include <vector>
using namespace  std;

int N; // ahgjark
int main(){
    int arrays[501];
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arrays[i];
    }

    sort(arrays, arrays + N);

    int result = 0;
    int count = 0;
    for(int i = 0 ; i< N ; i++){
        count++;
        int now = arrays[i];

        if (count >= now) {
            result++;
            count= 0;
        }
    }
    cout << result;
};



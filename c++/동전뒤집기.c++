// page 312
// 곱하기 혹은 더하기
// 11;12
// 2/16
// Grid Algorithm
#include <iostream>
#include <algorithm>
#include <string>
using namespace  std;

string numbers;
int main(){
    cin >> numbers;
    int count0 = 0;
    int count1 = 0;

    if (numbers[0] == '0') {
        count1++;
    }
    else {
        count0++;
    }

    for (int i = 0; i < numbers.size() - 1; i++) {
        if (numbers[i] != numbers[i + 1]) {
            if (numbers[i+1] == '0') {
                count1++;
            }
            else
                count0++;
        }
    }
    cout << min(count1, count0);
}



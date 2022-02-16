// 러키스트라이크 , 12:2

#include <iostream>
#include <string>

using namespace std;
int main(){
    int N;
    cin >> N;

    int left_sum = 0;
    int right_sum = 0;

    string s_n = "";

    while (N >= 10) {
        s_n += N % 10 + '0';
        N /= 10;
    }
    s_n += N % 10 + '0';

    for (int i = 0; i < s_n.size()/2; i++) {
        right_sum  += s_n[i] - '0';
        left_sum  += s_n[s_n.size() - i - 1] - '0';
    }

    if (right_sum == left_sum) {
        cout << "LUCKY";
    } else {
        cout << "READY";
    }


}
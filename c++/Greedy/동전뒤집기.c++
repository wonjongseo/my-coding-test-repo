#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


int main() {
    string coins;
    cin >> coins;

    int one_c = 0;
    int zero_c = 0;
    int prev_coin = coins[0] - '0';

    if (prev_coin == 0) {
        one_c++;
    } else zero_c++;


    for (int i = 1; i < coins.size(); i++) {
        int now = coins[i] - '0';

        if (now != prev_coin) {
            if (now == 0) {
                one_c++;
            } else zero_c++;
        }
        prev_coin = now;
    }

    cout << min(one_c, zero_c);
}
//01101010

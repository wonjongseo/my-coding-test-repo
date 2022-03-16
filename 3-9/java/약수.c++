#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

vector<int> real;
int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int tmp ;
        cin >>tmp;

        real.push_back(tmp);
    }

    sort(real.begin(), real.end());
    if (real.size() == 1) {
        cout << real[0] * real[0];
    }
    else{
        cout << real[0] * real[real.size() - 1];
    }
}

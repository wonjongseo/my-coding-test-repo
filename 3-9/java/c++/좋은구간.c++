#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

vector<int> real;
int main() {

    int L ; cin >> L;
    int n;

    int right = 1001, left = -1001;

    int arr[51];

    for (int i = 0; i < L; i++) {
        cin >> arr[i];
    }

    cin >> n;

    for (int i = 0; i < L; i++) {
        if(arr[i] - n >= 0){
            right = min(right, arr[i] - n);
        }
        else {
            left = max(left, arr[i] - n);
        }
    }

    if (right != 1001 && left != -1001 && right != 0) {
        cout << abs(right * left) - 1;
    } else if (left == -1001 && right != 0) {
        cout << n * right - 1;
    }
    else if (right == 0) {
        cout << 0;
    }


}

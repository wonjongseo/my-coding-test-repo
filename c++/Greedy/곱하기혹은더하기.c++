#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main(){
    string nums;
    cin >> nums;

    int sum = nums[0] - '0';

    for (int i = 1; i < nums.size(); i++) {
        int now = nums[i] - '0';
        if (sum <= 1 || now <= 1) {
            sum = sum + now;
        }
        else
            sum = sum * now;
    }

    cout << sum;
}
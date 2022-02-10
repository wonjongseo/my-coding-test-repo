#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int countByRange(vector<int> & v, int leftValue, int rightValue){
    vector<int>::iterator rightIndex = upper_bound(v.begin(), v.end(), rightValue);
    vector<int>::iterator leftIndex = lower_bound(v.begin(), v.end(), leftValue);

    return rightIndex - leftIndex;
}
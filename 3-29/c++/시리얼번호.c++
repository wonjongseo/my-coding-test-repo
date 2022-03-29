#include <iostream>
#include <vector>
#include <algorithm>


using namespace  std;

vector<string> arr;
int N;
bool cmp (string u, string v){
    int lenU = u.size();
    int lenV = v.size();

    if (lenU != lenV) return lenU < lenV;

    int sumU = 0;
    int sumV = 0;

    for (int i = 0; i < lenU; i++) {
        if(isdigit(u[i])) sumU += (u[i] - '0');
    }


    for (int i = 0; i < lenV; i++) {
        if(isdigit(v[i])) sumV += (v[i] - '0');
    }


    if(sumU != sumV) return sumU < sumV;

    return u < v;
}


int main(){
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }

    sort(arr.begin(), arr.end(), cmp);
    for (int i = 0; i < N; i++) {
        cout << arr[i] <<endl;
    }
}
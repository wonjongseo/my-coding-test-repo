#include<iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

int n ;

unordered_set <string> s;
string name;
string st;

int main(){
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n ;

    for (int i = 0; i < n; i++) {

        cin >> name >> st;

        if (st == "enter") {
            s.insert(name);
        }
        else{
            s.erase(name);
        }
    }
    vector<string> ans(s.begin(), s.end());
    sort(ans.begin(), ans.end(), greater<>());

    for(auto y : ans) cout << y << "\n";


}

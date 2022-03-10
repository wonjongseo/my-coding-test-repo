#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int cmp(string a, string b){
    if (a.size() == b.length()) {
        return  a < b;
    }
    else {
        return a.length() < b.length();
    }
}

int main() {
    int n;
    scanf("%d", &n);
    vector<string> words;

    for (int i = 0; i < n; i++) {
        string temp ;
        cin >> temp;
        words.push_back(temp);
    }
    sort(words.begin(), words.end(), cmp);

    for (int i = 0; i < words.size(); i++) {
        if(words[i] == words[i-1]){
            continue;
        }

        printf("%s\n", words[i].c_str());
    }

}

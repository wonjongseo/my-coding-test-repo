#include <queue>
#include<algorithm>
#include <iostream>
#define INF 1e9
using namespace std;
int d[7];
bool visited[7];
vector<vector<pair<int,int>>> map = {
        {},
        {{2,2}, {3,5}, {4,1}},
        {{3,3}, {4,2}},
        {{2,3}, {6,5}},
        {{3,3}, {5,1}},
        {{3,1}, {6,2}},
        {}
};

int findMinDistance(){

    int min = INF -1;
    for (int i = 1; i <= 6; i++) {
        if (min > d[i] && !visited[i]) {
            min = i;
        }
    }
    return min;
}
int main(){
    // dijkstra

    int start = 1;
    fill(d, d + 7, INF);
    d[start] = 0;
//
//    for (int i = 0; i < map[start].size(); i++) {
//        d[map[start][i].first] = map[start][i].second;
//    }

    for (int i = 1; i <= 5; i++) {
        int now = findMinDistance();
        visited[now] = true;

        for (int next = 0; next < map[now].size(); next++) {
            if (d[map[now][next].first] > d[now] + map[now][next].second) {
                d[map[now][next].first] = d[now] + map[now][next].second;
            }
        }
    }


    for (int i = 1; i <= 6; i++) {
        printf("%d ", d[i]);
    }


}

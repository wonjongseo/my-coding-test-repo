#include <queue>
#include<algorithm>
#include <iostream>
#define INF 1e9
using namespace std;

int n , m , start;
vector<pair<int, int>> graph[100001];
int d[100001];

void dijkstra_with_priority_queue(int start){
    // priority_queue 는 기본값이 최대
    priority_queue<pair<int,int>> pq;
    pq.push({0, start});
    d[start] = 0;
    while (!pq.empty()) {
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if(d[now] < dist) continue;

        for (int i = 0; i < graph[now].size(); i++) {
            int cost = dist + graph[now][i].second;
            if (cost < d[graph[now][i].first]) {
                d[graph[now][i].first] = cost;
                pq.push({-cost, graph[now][i].first});
            }
        }


    }
}

int main(){
}

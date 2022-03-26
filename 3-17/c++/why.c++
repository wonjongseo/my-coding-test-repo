#include <queue>
#include<algorithm>
#include <iostream>
#define INF 1e9
using namespace std;

vector<pair<int, int>> graph[20001];
int d[20001];
int V, E , start;

void dijkstra(int start){
    priority_queue<pair<int,int>> pq;
    d[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if(d[now] < dist) continue;

        for(int i = 0; i < graph[now].size(); i++) {
            int cost = graph[now][i].second + dist;
            if (cost < d[graph[now][i].first]) {
                d[graph[now][i].first] = cost;
                pq.push({-cost, graph[now][i].first});
            }
        }
    }

    for (int i = 1; i <= V; i++) {
        if (d[i] == INF) {
            cout << "INF" << endl;
        }
        else
            cout << d[i] << endl;
    }
}

int main(){
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);

    cout.tie(NULL);

    cin >> V >> E;
    fill(d, d + V + 1, INF);
    cin >> start;


    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    dijkstra(start);






}
#include <queue>
#include <vector>
#include <iostream>
#define INF 1e9
using namespace std;

int n , m , x , k;
vector<pair<int,int>> g[300001];
int d[300001];

void dijkstra(int start){
    priority_queue<pair<int,int>> queue;
    queue.push({0, start});
    d[start]=0;
//    for (int i = 0; i < g[start].size(); i++) {
//        d[g[start][i].first] = g[start][i].second;
//    }

    while (!queue.empty()) {
        int dist = -queue.top().first;
        int now = queue.top().second;
        queue.pop();

        if(dist > d[now]) continue;

        for (int i = 0; i < g[now].size(); i++) {
            int cost = dist + g[now][i].second;

            if (cost < d[g[now][i].first]) {
                d[g[now][i].first] = cost;
                queue.push({-cost, g[now][i].first});
            }
        }
    }
}
int main(){
    cin >> n >> m >> k >> x;

    for (int i = 0; i < m; i++) {
        int a ,b ;
        cin >> a >> b;
        g[a].push_back({b, 1});
    }

    fill(d, d + n + 1, INF);

    dijkstra(x);

    for (int i = 1; i <= n; i++) {
        if (d[i] == k) {
            printf("%d", i);
        }
//        printf("%d\n", d[i]);
    }

}
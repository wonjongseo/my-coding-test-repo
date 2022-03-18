#include <queue>
#include<algorithm>
#include <iostream>

#define  X first
#define  Y second
using namespace std;

vector<pair<int, int>> graph[20001];
const int INF = 0x3f3f3f3f;
int d[20001];
int V, E , start;

void dijkstra(){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    d[start] = 0;
    // 우선순위 큐에 (0, 시작점) 추가
    pq.push({d[start],start});
    while(!pq.empty()){
        auto cur = pq.top(); pq.pop(); // {비용, 정점 번호}
        // 거리가 d에 있는 값과 다를 경우 넘어감
        if(d[cur.Y] != cur.X) continue;
        for(auto nxt : graph[cur.Y]){
            if(d[nxt.Y] <= d[cur.Y]+nxt.X) continue;
            // cur를 거쳐가는 것이 더 작은 값을 가질 경우
            // d[nxt.Y]을 갱신하고 우선순위 큐에 (거리, nxt.Y)를 추가
            d[nxt.Y] = d[cur.Y]+nxt.X;
            pq.push({d[nxt.Y],nxt.Y});
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
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> V >> E;
    fill(d, d + V + 1, INF);
    cin >> start;

    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({c, b});
    }

    dijkstra();

}
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;

int n,m;

vector<pair<int,int>> map[1005];
int d[1005];
void dijkstra(int START, int* prev){

    priority_queue<pair<int,int>> Q;
    d[START] = 0;
    Q.push({0,START});

    while (!Q.empty()) {
        int dist = -Q.top().first;
        int now = Q.top().second;
//        printf("%d\n", now);
        Q.pop();

        if (d[now] < dist) {
            continue;
        }

        for (int i = 0; i < map[now].size(); i++) {
            int cost = dist + map[now][i].first;
            int next = map[now][i].second;
            if (d[next] > cost) {
                d[map[now][i].second] = cost;
                Q.push({-cost, map[now][i].second});
                prev[next] = now;
            }
        }
    }


}


int main(){
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cin >> n >> m;
    int START ,END;
    int prev[10001] = {0};
    for (int i = 0; i < m; i++) {

        int start , End, weight;

        cin >> start >> End >> weight;

        map[start].push_back({weight, End});
    }
//    cin >> start >> End;
    fill(d, d + n+1, INF);

    cin >> START >> END;
    dijkstra(START, prev);


    printf("%d\n", d[END]);
    vector<int> path;
    int cur = END;
    while (cur != START) {
        path.push_back(cur);
        cur = prev[cur];
    }

    path.push_back(cur);

    reverse(path.begin(), path.end());

    cout << path.size() << "\n";

    for(auto x  : path) cout << x << " ";

    return 0;







}

#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9

using namespace  std;

int N, M; //N = 마을, M 도로



// 두개된 불리된 마을로 분활계획.
// 전형적인 쿠루스칼 알고리즘이죠


vector<pair<int, pair<int, int>>> edges;
//int edges[1000001];
int parent[100001];


int findParent(int a){
    if (parent[a] != a) {
        parent[a] = findParent(parent[a]);
    }

    return parent[a];
}


int Union(int a, int b){
    a = findParent(a);
    b = findParent(b);

    if (a < b) {
        parent[b] = a;
    } else parent[a] = b;
}

int main(){
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }
    int weight=  0;

    for (int i = 0; i < M; i++) {
        int cost , a , b;
        cin >> a >> b >> cost;
        edges.push_back({cost,{a, b}});
    }
    std::sort(edges.begin(), edges.end());

int last;
    for (int i = 0; i < edges.size() ; i++) {
        int cost = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;

        if (findParent(a) == findParent(b)) {
            continue;
        }
        else{
            weight += cost;
            last = cost;
            Union(a, b);
        }
    }


    cout << weight-last;
/*
 7 12
 1 2 3
 1 3 2
 3 2 1
 2 5 2
 3 4 4
 7 3 6
 5 1 5
 1 6 2
 6 4 1
 6 5 3
 4 5 3
 6 7 4
 */

}






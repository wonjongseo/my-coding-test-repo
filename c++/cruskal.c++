#include <iostream>
#include <vector>
#define INF 1e9

using namespace  std;


int parent[10001]= {0,};
vector<pair<int ,pair<int,int>>> edges;
int v,e;
int findParent(int x){
    if( parent[x] != x ){
        parent[x] = findParent(parent[x]);
    }
    return parent[x];
}

void Union(int a, int b){
    a = findParent(a);
    b = findParent(b);

    if(a < b) {
        parent[b] = a;
    }
    else {
        parent[a] = b;
    }
}


int main(){
    cin >> v >> e;

    for(int i = 1; i <= v;i++){
        parent[i] = i;
    }

    int weight = 0;

    for(int i = 0 ;i< e ; i++){
        int a,b,cost;
        cin >> a >> b >> cost;

        edges.push_back({cost ,{a, b}});
    }
    std::sort(edges.begin(), edges.end());

    for(int i=0 ; i < edges.size(); i++){
        int cost = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;

        if (findParent(a) != findParent(b)) {
            Union(a, b);
            weight += cost;
        }
    }

    cout << weight;






}

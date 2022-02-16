#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9

using namespace  std;

int M,N;
int parent[100001];

int findParent(int a){
    if (parent[a] != a) {
        parent[a] = findParent(parent[a]);
    }
    return parent[a];
}

void Union(int a, int b){
    a = findParent(a);
    b = findParent(b);
    if (a < b) {
        parent[b] = a;
    }
    else
        parent[a] = b;
}


int main(){
    cin >> N >> M;

    for (int i = 0; i <= N; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < M; i++) {
        int x,a,b;
        cin >> x >> a >> b;
        switch (x) {
            case 0:
                Union(a, b);
                break;
            case 1:
                if (findParent(a) == findParent(b)) {
                    cout << "YES" <<endl;
                }
                else
                    cout << "NO" << endl;
                break;

        }
    }


}


/*
 7 8
0 1 3
1 1 7
0 7 6
1 7 1
0 3 7
0 4 2
0 1 1
1 1 1


 */
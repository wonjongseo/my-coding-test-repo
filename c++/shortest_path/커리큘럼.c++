#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9

using namespace  std;

int N, M;
vector<int> graph[501];
int times[501];
int indegree[501];

int main(){
    cin >> N ;

    for (int i = 1; i <= N; i++) {
        int time ;
        cin >> time;
        times[i] = time;

        int to;
        cin >> to;

        while (to != -1) {
            graph[to].push_back(i);
            cin >> to;
            indegree[i]++;
        }
    }

    queue<int> q ;

    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int now = q.front();
        q.pop();



        for (int i = 0; i < graph[now].size(); i++) {
            int incident = graph[now][i];
            times[incident] += times[now];
            indegree[incident]--;

            if (indegree[incident] == 0) {
                q.push(incident);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << times[i] << " ";
    }


    /*
5
10 -1
10 1 -1
4 1 -1
4 3 1 -1
3 3 -1
     */




}
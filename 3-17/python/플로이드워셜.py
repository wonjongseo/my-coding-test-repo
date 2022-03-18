# 모든 간선들의 최소 거리를 찾는 알고리즘
import sys
input = sys.stdin.readline

INF = int(1e9)
n = int(input())
m = int(input())
graph = [[INF] * (n+1) for _ in range(n+1)]

for a in range(1 , n+1):
    for b in range(1 , n+1):
        if a==b:
            graph[a][b] = 0


for _ in range(m):
    a , b, c = map(int, input().split())
    graph[a][b] =c


for k in range(1, n+1): # 거쳐가는 노드
    for a in range(1 ,n+1): # 출발노드
        for b in range(1, n+1): #도착노드
            # 에이에서 비로 가는 것이과 에이에서 케이를 갔다가 케이에서 비를 가는 것과 비교하는 것중
            # 더 낮은 것을 선택
            graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b])


for a in range(1, n+1):
    for b in range(1,n+1):
        if graph[a][b] == INF:
            print("INFINITY", end=" ")
        else:
            print(graph[a][b], end=" ")
    print()



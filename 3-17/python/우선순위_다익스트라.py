# 출발 노드에서 다른 노드까지의 최단거리를 구하는 알고리즘
import sys
import heapq

input = sys.stdin.readline
INF = int(1e9)

n, m = map(int, input().split())

start = int(input())

graph = [[] for i in range(n+1)]

d = [INF] * (n+1)

for _ in range(m):
    a, b, c = map(int, input().split())
    graph[a].append((b,c))


def dijkstra(start):
    heap = []
    d[start] = 0
    heapq.heappush(heap, (0 ,start))

    while heap:
        dist, now = heapq.heappop(heap)

        if d[now] < dist:
            continue

        for j in graph[now]:
            cost = j[1] + dist
            if cost < d[j[0]]:
                d[j[0]] = cost
                heapq.heappush(heap, (cost , j[0],))









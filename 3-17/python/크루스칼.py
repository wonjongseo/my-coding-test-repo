
# 최소신장트리
# 크루스칼 알고리즘
# 그리디 알고리즘
# 동작 과정
# 1. 간선 데이터를 비용에 따라 오름차순 정렬
# 2. 간선을 하나씩 확인하며 현재의 간선이 사이클이 발생시키는지 확인
#   2-1 사이클이 발생하지 않는 경우 최소 신장 트리에 포함시킴
#   2-2 사이클이 발생하면 최소 신장 트리에 포함시키지 않음
# 3. 모든 간성에 대하여 2번 과정 반복

# 성능
# 크르수칼 알고리즘은 간선의 개수가 E 일때 O(E log(E)) 의 시간 복잡도를 갖는다
# 


def find_parent(parent, x):
    if parent[x] != x:
        parent[x] = find_parent(parent, parent[x])
    return parent[x]

def Union(parent ,a ,b):
    a = find_parent(parent,a)
    b = find_parent(parent,b)
    if a < b:
        parent[b] = a
    else:
        parent[a] =b

v, e = map(int, input().split())
parent = [0] * (v+1)
edges = []
result = 0
for i in range(1, v+1):
    parent[i] = i

for _ in range(e):
    a, b, cost = map(int, input().split())
    edges.append((cost, a, b))

edges.sort()

for edge in edges:
    cost, a, b, = edge
    a = find_parent(parent, a)
    b = find_parent(parent, b)

    if a == b:
        continue

    result = result + cost
    Union(parent ,a,b)

print(result)


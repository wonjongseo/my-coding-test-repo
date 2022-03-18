
# 서로소 집합은 무방향 그래프 내에서 사이클 판별할 때 사용가능
#   참고로 방향 그래프에서 사이클 여부는 DFS
# 무방향 간선 사이클 판별 알고리즘은
# 1. 각 간선을 하나씩 확인하며 두 노드의 루트 노드 확인
#    1-1 루트 노드가 서로 다르다면 합집합
#    1-2 루트 노드가 서로 같다면 사이클 발생
# 2 그래프에 포함되어 있는 간선에 대하여 1번 과정을 반

v,e = map(int, input().split())

parent = [0] * (v+1)

for i in range(1, v+1):
    parent[i] = i

cycle = False

def find_parent(parent, x):
    if parent[x] != x:
        parent[x] = find_parent(parent, parent[x])
    return  parent[x]

def Union(parent, a,b):
    a = find_parent(parent, a)
    b = find_parent(parent, b)

    if a < b:
        parent[b] =a
    else:
        parent[a] =b

for _ in range(e):
    a, b = map(int, input().split())
    a = find_parent(parent,a)
    b= find_parent(parent,b)

    if a == b:
        cycle = True
        break
    else:
        Union(parent,a,b)

if cycle:
    print("Have cycle")
else:
    for i in range(1,v+1):
        print(find_parent(parent,i), end=" ")


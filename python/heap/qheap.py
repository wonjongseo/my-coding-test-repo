import heapq

# 최소힙
def minheapsort(iterable):
    h = []
    result = []

    for value in iterable:
        heapq.heappush(h,value)
    for i in range(len(h)):
        result.append(heapq.heappop(h))
    return result

result =  minheapsort([1,5,6,3,2,5,8,4])

print(result)

# 최힙

def maxheapsort(iterable):
    h = []
    result = []

    for value in iterable:
        heapq.heappush(h,-value)
    for i in range(len(h)):
        result.append(-heapq.heappop(h))
    return result

result =  maxheapsort([1,5,6,3,2,5,8,4])

print(result)
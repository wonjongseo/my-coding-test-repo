# 선택정렬
# 처리되지 않은 데이터 중 가장 작은 데이터를 선택해 맨 앞의 데이터와 바꾸는 것을 반복

arr = [7,5,9,0,3,1,6,2,4,8]

for i in range (len(arr)):
    min_idx = i
    for j in range(i+1, len(arr)):
        if arr[min_idx] > arr[j]:
            min_idx = j

    arr[i], arr[min_idx] = arr[min_idx], arr[i],


# 삽입
# 선택 정렬보다 일반벅으로 더 효율적
# 거의 정렬되어 있는 경우는 O(n), Or O(n*n)
arr1 = [7,5,9,0,3,1,6,2,4,8]

for i in range(1, len(arr1)):
    for j in range(i, 0, -1): # i부터 1까지
        if arr1[j] < arr1[j-1]:
            arr[j], arr[j-1] = arr[j-1], arr[j],
        else:
            break


# 퀵정렬 O(Nlog(N))
# 기존 데이터를 설정하고 그 기준보다 큰 데이터와 작은 데이터의 위치를 바꾸는 방법
# 일반적인 상황에서 가장 많이 사용되는 알고리즘



def quick_sort(arr, start, end):
    if start >= end:
        return
    pivot = start
    left = start + 1
    right = end

    while left <= right:

        while left <= end and arr[left] <= arr[pivot]:
            left+=1
        while right > start and arr[right] >= arr[pivot]:
            right-=1

        if left > right :
            arr[pivot], arr[right] = arr[right], arr[pivot],
        else :
            arr[left] , arr[right] = arr[right], arr[left]

    quick_sort(arr, start, right-1)
    quick_sort(arr, right+1, end)

arr2 = [7,5,9,0,3,1,6,2,4,8]
quick_sort(arr2, 0, len(arr2) -1)

print(arr2)

def quick_sort_for_python(arr):
    if len(arr) <= 1:
        return  arr

    pivot = arr[0]
    tail = arr[1:]

    left_side = [x for x in tail if x <= pivot]
    right_side = [ x for x in tail if x>= pivot]

    return quick_sort_for_python(left_side) + [pivot] + quick_sort_for_python(right_side)



# 계수 정렬
# 특정한 조건이 부합할때만 사용 가능하지만 매우 빠르게 동작하는 정렬 알고리즘
# 계수 정렬은 데이터의 크기 범위가 제한되어 정수 형태로 표현할 수 있을 때 사용 가능
# 데이터의 개수 N , 데이터 (양수) 중 최대값이 K 일때 최악의 경우에도 수행시간이 O(N+K)

arr3 = [7,5,9,0,3,1,6,2,4,8, 12,12]
count = [0] * (max(arr3) + 1)

for i in range(len(arr3)):
    count[arr3[i]] += 1

for i in range(len(count)):
    for j in range(count[i]):
        print(i, end= ' ')






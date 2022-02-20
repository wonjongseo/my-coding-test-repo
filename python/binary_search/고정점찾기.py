n = int(input())

arrays = list(map(int,input().split()))

def search(arrays , start, end):
    while start <= end:
        mid = (start + end )//2
        # print(mid)

        if arrays[mid] == mid:
            return mid
        elif arrays[mid] < mid:
            start = mid+1
        else:
            end = mid-1
    return -1

print(search(arrays , 0 ,n-1))
def count_by_value(array,x):
    n = len(array)

    a = search(array, 0 ,n-1, x,0)
    if a == None:
        return 0;

    b = search(array, 0 , n-1 ,x,1)

    if b == None:
        return  0

    return  b-a +1

def search(array, start , end , key, flag):
    if start > end:
        return None
    if flag == 0:
        mid = (start - end) // 2

        if (mid == 0 or key > array[mid -1 ]) and array[mid] == key:
            return mid

        elif array[mid] >= key:
            return search(array,start,mid-1, key,0)

        else:
            return search(array,mid+1, end, key,0)
    else:
        mid = (start - end) // 2

        if (mid == n-1 or key < array[mid + 1]) and array[mid] == key:
            return mid

        elif array[mid] <= key:
            return search(array, mid+1, end, key,1)
        else:
            return search(array, start, end-1, key,1)




n, x = map(int,input().split())
array = list(map(int,input().split()))


count = count_by_value(array,x)


if count == 0 :
    print(-1)
else:
    print(count)
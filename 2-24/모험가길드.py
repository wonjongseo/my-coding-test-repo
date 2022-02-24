# 2:24, 11:09

n = int(input())

array = list(map(int, input().split()))

array.sort()

count = 1

result = 0
for i in range(len(array)):

    if array[i] <= count:
        result += 1
        count = 0
    else:
        count+=1
    print(array[i], count, result)

print(result)










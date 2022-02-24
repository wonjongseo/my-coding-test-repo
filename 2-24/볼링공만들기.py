# 2:24 , 12:00
# 볼링공만들기

n, m = map(int,input().split())

arrays = list(map(int,input().split()))

# count = 0
# for i in range(len(arrays)):
#     for j in range(i+1, len(arrays)):
#         if arrays[i] != arrays[j]:
#             count += 1
# 
# print(count)

balls= [0] *11 

for i in arrays:
    balls[i] +=1

result = 0

for i in range(1,m+1):
    n -= balls[i]
    result += arrays[i] * n
    
    


# 5 3
# 1 3 2 3 2
n = int(input())
numbers = list(map(int, input().split()))

add, sub , mul, divi = map(int, input().split())

max_result = -1e9
min_result = 1e9

def dfs(i,now):
    global max_result, add, sub,mul,divi, min_result

    if i == n :
        max_result = max(max_result ,now)
        min_result = min(min_result, now)

    if add > 0 :
        add -= 1
        dfs(i+1 , now + numbers[i])
        add += 1
    if sub > 0 :
        sub -= 1
        dfs(i+1 , now - numbers[i])
        sub += 1
    if mul > 0 :
        mul -= 1
        dfs(i+1 , now * numbers[i])
        mul += 1
    if divi > 0 :
        divi -= 1
        dfs(i+1 , int(now / numbers[i]))
        divi += 1


dfs(1,numbers[0])

print(max_result)
print(min_result)





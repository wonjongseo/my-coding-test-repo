import sys
input = sys.stdin.readline

N = int(input().rstrip())

Arr = [()] * N

for i in range(N):
    item = input().rstrip()
    sum = 0
    for Char in item :
        if Char.isdigit():
            sum += int(Char)
    Arr[i] = (item,sum)

Arr = sorted(Arr , key=lambda item : (
    len(item[0]), item[1], item[0]
))

for item in Arr:
    print(item[0])

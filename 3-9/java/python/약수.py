t = int(input())

real2 = list(map(int,input().split()))

real2.sort()

print(real2[0] * real2[len(real2)-1])
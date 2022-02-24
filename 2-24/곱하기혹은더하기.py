# 2:24, 11:20

nums = input()

sum = int(nums[0])


for i in range(1,len(nums)):
    if sum <= 0 or int(nums[i]) <= 0 :
        sum = sum + int(nums[i])
    else:
        sum = sum * int(nums[i])
print(sum)






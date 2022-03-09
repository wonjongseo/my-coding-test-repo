# 2:24 , 1
# 러키스트라이크

data = input()

# 1 5 -> 1 2
front_sum =0
end_sum = 0
for i in range(0,len(data) //2):
    front_sum += int(data[i])


for i in range(len(data)//2 , len(data)):
    end_sum += int(data[i])


if front_sum == end_sum :
    print("LUCKY")
else :
    print("READY")




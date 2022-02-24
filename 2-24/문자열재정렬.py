# 2:24 , 1:11
# 문자열 재정리

datas = input()
new_data = []
num = 0
for data in datas:
    if data.isalpha():
        new_data +=data
    else:
        num+= int(data)
new_data.sort()
if num != 0:
    new_data += str(num)

for i in new_data:
    print(i,end="")


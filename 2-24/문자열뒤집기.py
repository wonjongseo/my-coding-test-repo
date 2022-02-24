# 2:24 , 11:24

arrays = input()

onw_num = 0;
zero_num = 0;
prev = arrays[0]

if arrays[0] == '0':
    onw_num += 1
else:
    zero_num += 1

for i in range(1, len(arrays)):
    if prev != arrays[i]:
        if arrays[i] == '0':
            onw_num += 1
        else:
            zero_num += 1
    prev = arrays[i]

print(min(onw_num, zero_num))


# 10111001
# 101010101010
# 110101010101
# 0001100



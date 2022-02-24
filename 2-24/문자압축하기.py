# 2:24 , 1:16
# 문자열 압축

# str2 = "aabbaccc"
str2 = "ababcdcdababcdcd"

answer = len(str2)

for step in range(1, len(str2) // 2 +1):
    new_str = ""
    prev = str2[0:step]
    count = 1

    for j in range(step, len(str2) , step):
        if prev == str2[j:j+step]:
            count += 1
        else:
            new_str += str(count) + prev if count >= 2 else prev
            prev = str2[j: j + step]
            count = 1
    new_str += str(count) + prev if count >= 2 else prev
    answer = min(answer , len(new_str))

print(answer)











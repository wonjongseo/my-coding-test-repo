import sys
import re

n  = int(sys.stdin.readline())

List = []
for _ in range(n):
    List.append(sys.stdin.readline().rstrip())




List2 = [0] * n
def Merge(st, en):
    global  List, List2
    mid = (st + en) // 2
    i = st
    j = mid+1
    k = st

    while i<= mid and j<= en:
        flag = 0
        if len(List[i]) == len(List[j]):
            inumbers = map(int,re.findall("\d",List[i]))
            iNumb = sum(inumbers)

            jnumbers = map(int, re.findall("\d", List[j]))
            jNumb = sum(jnumbers)

            if iNumb < jNumb :
                List2[k] = List[i]
                i+=1
                k+=1
                flag =1
            elif  iNumb > jNumb :
                List2[k] = List[j]
                j += 1
                k += 1
                flag = 1
        else :
            if len(List[j]) < len(List[i]):
                List2[k] = List[j]
                j+=1
                k += 1
                flag = 1
            elif len(List[j]) > len(List[i]) :
                List2[k] = List[i]
                i += 1
                k += 1
                flag = 1
        if flag == 0:

            if List[j] < List[i]:
                List2[k] = List[j]
                j += 1
                k += 1
            else:
                List2[k] = List[i]
                i += 1
                k += 1

    Tmp = 0
    if mid < i:
        Tmp = j
    else:
        Tmp = i
    while k <= en :
        List2[k] = List[Tmp]
        Tmp+=1
        k+=1

    for i in range(st, en+1):
        List[i] = List2[i]




def Partition(st,en):
    if st < en :
        mid =(st+en)//2
        Partition(st,mid)
        Partition(mid+1, en)
        Merge(st,en)

Partition(0,n-1)

# for i in List:
    # print(i)


for i in List:
    print(i)

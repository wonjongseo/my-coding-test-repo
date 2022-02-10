
import sys;
n = int(input())

products = list(map(int,sys.stdin.readline().rstrip().split()))
products.sort()

m = int(input())

wanted = list(map(int,sys.stdin.readline().rstrip().split()))



def findProduct(start, end , product):
    if start > end :
        return False
    mid = (start + end )//2 

    if products[mid] == product :
        return True
    elif products[mid] > product :
        return findProduct(start, mid-1 , product)
    else :
        return findProduct(mid+1, end , product)



for i in range(len(wanted)):
    if findProduct(0,n-1,wanted[i]) == True:
        print("Yes ",end=' ')
    else:
        print("No ",end=' ')

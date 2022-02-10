from array import array
from cmath import pi
from turtle import st


arrays = [ 5,7,9,0,3,1,6,2,4,8]


def quick_sort(array, start, end):
    if start >= end:
        return
    pivot = start

    left = start+1
    right = end
    while left <= right :
        while left <= end and arrays[left] <= arrays[pivot]:
            left += 1
        while right > start and array[right] >= array[pivot]:
            right -= 1
        
        if left > right :
            array[right], array[pivot]  =  array[pivot] , array[right]
        else :
            array[right], array[left]  =  array[left] , array[right]

    quick_sort(array, start, right -1)
    quick_sort(array, right+1,end)
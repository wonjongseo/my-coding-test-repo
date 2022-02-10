arrays = [7,5,9,0,3,1,6,2,4,8]

for i in range(len(arrays)-1):
    min_index = i
    for j in range(i+1 , len(arrays)): 
        if arrays[j] < arrays[min_index]:
            min_index = j
    
    # tmp = arrays[min_index]
    # arrays[min_index] = arrays[i]
    # arrays[i] = tmp
    arrays[i], arrays[min_index] = arrays[min_index], arrays[i]

print(arrays)        

arrays = [7,5,9,0,3,1,6,2,4,8]


# for i in range(1, len(arrays)):
    # j = i
    # while arrays[j-1] > arrays[j] :
        # if j < 0 : break
        # arrays[j-1], arrays[j] =  arrays[j], arrays[j-1]
        # j -= 1
    
    


for i in range(1, len(arrays)):
    for j in range(i, 0 , -1) :
        if arrays[j]  < arrays[j-1] :
            arrays[j] ,arrays[j-1]  =   arrays[j-1], arrays[j] 
        else:
            break

print(arrays)

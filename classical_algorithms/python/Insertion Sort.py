def insertion_sort(array):
    
    for i in range(1,len(array)):
        j = i-1
        key = array[i]
        
        #move all the elements of array[0,i-1] that are greater than
        #the key, one position ahead of their current one
        
        while j>=0 and array[j]>key:
            array[j+1] = array[j]
            j = j-1
        
        array[j+1] = key
    
    print(array)
    

m = int(input('Enter the number of elements in the array '))

mylist = []

for i in range(0,m):
    num = int(input('Enter element: '))
    mylist.append(num)

insertion_sort(mylist)
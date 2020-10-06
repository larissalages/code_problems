def bubblesort(array):

    n = len(array)

    for i in range(0,n-1):
        for j in range(0,n-i-1):
            if (array[j] > array[j+1]):
                array[j] , array[j+1] = array[j+1] , array[j]
                
    print(array)


m = int(input('Enter the number of elements in the array '))

mylist = []

for i in range(0,m):
    num = int(input('Enter element: '))
    mylist.append(num)

bubblesort(mylist)

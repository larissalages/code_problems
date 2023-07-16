def insertion_sort(array):
    for i in range(1, len(array)):
        j = i - 1
        key = array[i]

        while j >= 0 and array[j] > key:
            array[j + 1] = array[j]
            j = j - 1

        array[j + 1] = key

    return array


if "__name__" == "__main__":
    m = int(input('Enter the number of elements in the array '))
    mylist = []
    for i in range(0, m):
        num = int(input('Enter element: '))
        mylist.append(num)
    print(insertion_sort(mylist))

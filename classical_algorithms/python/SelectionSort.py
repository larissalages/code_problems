class SelectionSort:
    def sort(self, array):
        if array is None:
            raise TypeError('array cannot be None')
        return self._sort(array)

    def _sort(self, array):
        if len(array) < 2:
            return array

        for i in range(len(array)):
            minimum = i
            for j in range(i+1, len(array)):
                if array[j] < array[i]:
                    array[i], array[j] = array[j], array[i]

        return array
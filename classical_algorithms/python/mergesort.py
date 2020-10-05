class MergeSort:
    def sort(self, array):
        if array is None:
            raise TypeError('array cannot be None')
        return self._sort(array)

    def _sort(self, array):
        if len(array) < 2:
            return array

        mid = len(array)//2
        left = self._sort(array[:mid])
        right = self._sort(array[mid:])
        return self._merge(left, right)

    def _merge(self, left, right):
        l = 0
        r = 0
        new_array = []
        while l < len(left) and r < len(right):
            if left[l] < right[r]:
                new_array.append(left[l])
                l += 1
            else:
                new_array.append(right[r])
                r += 1

        while l < len(left):
            new_array.append(left[l])
            l += 1

        while r < len(right):
            new_array.append(right[r])
            r += 1

        return new_array

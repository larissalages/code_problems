class Quicksort:
    def sort(self, data):
        if data is None:
            raise TypeError('data cannot be None')
        return self._sort(data)

    def _sort(self, data):
        if len(data) < 2:
            return data
        equal, left, right = [], [], []
        piv_index = len(data)//2
        piv_value = data[piv_index]

        for n in data:
            if n == piv_value:
                equal.append(n)
            elif n < piv_value:
                left.append(n)
            else:
                right.append(n)

        left = self._sort(left)
        right = self._sort(right)

        return left + equal + right

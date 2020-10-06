import unittest

class BinarySearch:
    def search(self, array, element):
        first = 0
        last = len(array) - 1

        while first <= last:
            mid = (first + last)//2
            if array[mid] == element:
                return mid
            else:
                if element < array[mid]:
                    last = mid - 1
                else:
                    first = mid + 1
        
        return False
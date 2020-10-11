import unittest
from classical_algorithms.python.BinarySearch import BinarySearch

class TestBinarySearch(unittest.TestCase):
    def test_binary_search(self):
        binary_search = BinarySearch()

        print('None Input')
        self.assertRaises(TypeError, binary_search.search, None)

        print('Empty Input')
        self.assertEqual(binary_search.search([], 1), False)

        print('One Element')
        self.assertEqual(binary_search.search([25], 25), 0)

        print('Two or More Elements')
        array = [0, 10, 15, 100, 150, 200, 203, 230]
        self.assertEqual(binary_search.search(array, 15), 2)

        print('Two or More with negative Elements')
        array = [-20, -15, -5, 0, 10, 15, 100, 150, 200, 203, 230]
        self.assertEqual(binary_search.search(array, -15), 1)

        print('Success: binary_search_search\n')

if __name__ == '__main__':
    unittest.main()
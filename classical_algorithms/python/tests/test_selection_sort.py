import unittest
from classical_algorithms.python.SelectionSort import SelectionSort

class TestSelectionSort(unittest.TestCase):
    def test_selection_sort(self):
        selection_sort = SelectionSort()

        print('None Input')
        self.assertRaises(TypeError, selection_sort.sort, None)

        print('Empty Input')
        self.assertEqual(selection_sort.sort([]), [])

        print('One Element')
        self.assertEqual(selection_sort.sort([25]), [25])

        print('Two or More Elements')
        array = [10, 1, 0, 100, 5, 15, 100, 7]
        self.assertEqual(selection_sort.sort(array), sorted(array))

        print('Two or More with negative Elements')
        array = [10, -1, 0, 100, 5, 15, -100, -7]
        self.assertEqual(selection_sort.sort(array), sorted(array))

        print('Success: selection_sort_sort\n')

if __name__ == '__main__':
    unittest.main()
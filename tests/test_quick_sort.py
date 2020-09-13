import unittest
from classical_algorithms.quicksort import Quicksort


class TestQuickSort(unittest.TestCase):
    def test_quick_sort(self):
        quick_sort = Quicksort()

        print('None Input')
        self.assertRaises(TypeError, quick_sort.sort, None)

        print('Empty Input')
        self.assertEqual(quick_sort.sort([]), [])

        print('One Element')
        self.assertEqual(quick_sort.sort([25]), [25])

        print('Two or More Elements')
        array = [10, -1, 0, 100, 5, 15, -100, 7]
        self.assertEquals(quick_sort.sort(array), sorted(array))

        print('Success: test_quick_sort\n')


def main():
    TestQuickSort.test_quick_sort()


if __name__ == '__main__':
    main()

import unittest
from classical_algorithms.python.mergesort import MergeSort


class TestMergeSort(unittest.TestCase):
    def test_merge_sort(self):
        merge_sort = MergeSort()

        print('None Input')
        self.assertRaises(TypeError, merge_sort.sort, None)

        print('Empty Input')
        self.assertEqual(merge_sort.sort([]), [])

        print('One Element')
        self.assertEqual(merge_sort.sort([25]), [25])

        print('Two or More Elements')
        array = [10, -1, 0, 100, 5, 15, -100, 7]
        self.assertEqual(merge_sort.sort(array), sorted(array))

        print('Success: test_merge_sort\n')


def main():
    TestMergeSort.test_merge_sort()


if __name__ == '__main__':
    main()

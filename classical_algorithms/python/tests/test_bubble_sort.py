import unittest

from classical_algorithms.python.BubbleSort import bubblesort


class TestBubbleSort(unittest.TestCase):
    def test_bubble_sort(self):
        # normal test 1
        self.assertEqual(bubblesort([64, 34, 25, 12, 22, 11, 90]), [11, 12, 22, 25, 34, 64, 90])
        # normal test 2
        self.assertEqual(bubblesort([5, 2, 9, 1, 5, 6]), [1, 2, 5, 5, 6, 9])
        # empty list
        self.assertEqual(bubblesort([]), [])
        # single-element list
        self.assertEqual(bubblesort([1]), [1])
        # reverse-ordered list
        self.assertEqual(bubblesort([9, 8, 7, 6, 5, 4, 3, 2, 1]),
                         [1, 2, 3, 4, 5, 6, 7, 8, 9])
        # negative list
        self.assertEqual(bubblesort([-1, -2, -3, -4]), [-4, -3, -2, -1])

if __name__ == '__main__':
    unittest.main()

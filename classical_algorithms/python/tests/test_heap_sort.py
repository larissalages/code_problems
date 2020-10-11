import unittest
from classical_algorithms.python.heapsort import heapSort

class TestHeapSort(unittest.TestCase):
  def test_heap_sort(self):

    print('None Input')
    self.assertRaises(TypeError, heapSort, None)

    print('Empty Input')
    self.assertEqual(heapSort([]), [])

    print('One Element')
    self.assertEqual(heapSort([13]), [13])

    print('Multipe nElements')
    test_array = [-23,-1,0,1,10,-10,1000, 2]
    solution_array = [-23,-10,-1,0,1,2,10,1000]

    self.assertEqual(heapSort(test_array), solution_array)

    print('Successful test_heap_sort\n')


if __name__=='__main__':
  unittest.main()

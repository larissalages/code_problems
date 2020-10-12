import unittest
from classical_algorithms.python.LinearSearch import linear

# linear(arr,n,x):

class TestLinaerSearch(unittest.TestCase):
  def test_linear_search(self):

    print('None Array')
    self.assertRaises(TypeError, linear(None,0,12))

    print('None Search')
    self.assertRaises(TypeError, linear([12,22],2,None))

    print('Empty Array')
    self.assertEqual(linear([],2,12), -1)

    print('Wrong size')
    self.assertRaises(TypeError, linear([1,2,3], 5, 2))

    print('One Element')
    self.assertEqual(linear([12], 1, 12), 0)

    print('Multiple Elements')
    self.assertEqual(linear([-100, -12, -1, 0, 1,2,3,4, 100], 9, 3), 6)





if __name__=='__main__':
  unittest.main()

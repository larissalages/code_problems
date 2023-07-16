import unittest

from classical_algorithms.python.sieveoferatosthenes import sieve_of_eratosthenes


class TestSieveOfEratosthenes(unittest.TestCase):
    def test_sieve_of_eratosthenes(self):
        #test case1
        self.assertEqual(sieve_of_eratosthenes(10), [2, 3, 5, 7])
        # test case2
        self.assertEqual(sieve_of_eratosthenes(20), [2, 3, 5, 7, 11, 13, 17, 19])
        # for 1
        self.assertEqual(sieve_of_eratosthenes(1), [])
        # for 2
        self.assertEqual(sieve_of_eratosthenes(2), [2])
        # for negative number
        self.assertEqual(sieve_of_eratosthenes(-1), [])


if __name__ == '__main__':
    unittest.main()

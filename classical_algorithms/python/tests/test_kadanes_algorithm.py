import unittest
from classical_algorithms.python.kadanes_algorithm import kadanes_algorithm


NUMS_LIST = [([-2, 1, -3, 4, -1, 2, 1, -5, 4], 6), ([-1], -1)]


class TestKadanesAlgorithm(unittest.TestCase):
    def test_kadanes_algorithm(self):
        for nums, expected_res in NUMS_LIST:
            with self.subTest():
                res = kadanes_algorithm(nums)
                self.assertEqual(res, expected_res)


if __name__ == "__main__":
    unittest.main()

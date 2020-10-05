import unittest
from classical_algorithms.python.radix import Radix


class TestRadix(unittest.TestCase):
    def test_radix(self):
        radix = Radix()

        print('None Input')
        self.assertRaises(TypeError, radix.sort, None)

        print('Empty Input')
        self.assertEqual(radix.sort([]), [])

        print('One Element')
        self.assertEqual(radix.sort([25]), [25])

        print('Two or More Elements')
        array = [10, 1, 0, 100, 5, 15, 100, 7, 500, 200]
        self.assertEqual(sorted(array), radix.sort(array))

        #  TODO: Include tests for negative numbers

        print('Success: test_radix\n')


def main():
    TestRadix.test_radix()


if __name__ == '__main__':
    main()

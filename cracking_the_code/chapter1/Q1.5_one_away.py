import unittest
import logging


# O(n) time
def one_edit_away(str1, str2):
    if abs(len(str1) - len(str2)) > 1:
        return False
    else:  # make str1 be always the longest
        if len(str2) > len(str1):
            tmp = str2
            str2 = str1
            str1 = tmp
        i = j = 0
        diff = False
        while i < len(str1) and j < len(str2):
            c1 = str1[i]
            c2 = str2[j]
            if c1 == c2:
                i += 1
                j += 1
            else:
                if diff is True:
                    return False
                diff = True
                if len(str1) == len(str2):
                    i += 1
                    j += 1
                else:
                    i += 1
        return True


class Test(unittest.TestCase):
    test_cases = (
        ("pale", "ple", True),
        ("", "", True),
        ("pale", "bale", True),
        ("pale", "pales", True),
        ("a", "b", True),
        ("pale", "paless", False),
        ("pale", "pas", False),
        ("pale", "pa", False)
    )

    def test_one_away(self):
        for str1, str2, expected in self.test_cases:
            result = one_edit_away(str1, str2)
            logging.info("Strings: ({}, {}); Result: {}; Expected: {}".format(str1, str2, result, expected))
            assert result == expected


if __name__ == '__main__':
    logging.basicConfig(
        level=logging.INFO,
        format='%(levelname)s - %(message)s'
    )
    unittest.main()

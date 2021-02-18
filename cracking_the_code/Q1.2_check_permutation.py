import unittest
"""
The first approach would be sort the strings and compare it. But sorting takes O(nlogn) (time), so we have to find a better approach.
The second approach (the one implemented here) uses the fact that if a string is a permutation of the other, it has to have
the same number of the exact same characters. The 2nd approach takes O(n) (time).
"""

def is_permutation(str1, str2):
    if len(str1) != len(str2):
        return False
    letters_count = {}
    # count the letters on string 1
    for c in str1:
        if c in letters_count:
            letters_count[c] += 1
        else:
            letters_count[c] = 1

    # the count of the letters in str2 has to be the same as str1
    for c in str2:
        if c not in letters_count:
            return False
        letters_count[c] -= 1
        if letters_count[c] < 0:
            return False

    return True


class Test(unittest.TestCase):
    test_cases = (
        ('asac', 'casa', True),
        ('love', 'lose', False),
        ('awefgr', 'awcvghj', False),
        ('DOG', 'dog', False),
        ('aaab', 'bbba', False),
        ('harry', 'arrhy', True)
    )

    def test_cp(self):
        for str1, str2, expected in self.test_cases:
            assert is_permutation(str1, str2) == expected


if __name__ == '__main__':
    unittest.main()

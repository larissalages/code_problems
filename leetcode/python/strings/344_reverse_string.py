class Solution:
    def reverseString(self, s) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        i = 0
        j = len(s) - 1

        while j > i:
            tmp = s[i]
            s[i] = s[j]
            s[j] = tmp
            j -= 1
            i += 1


def main():
    strg = ["h","e","l","l","o"]
    solution = Solution()
    solution.reverseString(strg)
    print("Result: {}".format(strg))


if __name__ == '__main__':
    main()

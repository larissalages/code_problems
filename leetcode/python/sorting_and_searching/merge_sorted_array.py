class Solution:
    def merge(self, nums1, m, nums2, n) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        while m > 0 and n > 0:
            if nums1[m-1] >= nums2[n-1]:
                nums1[m+n-1] = nums1[m-1]
                m -= 1
            else:
                nums1[m+n-1] = nums2[n-1]
                n -= 1
        while n > 0:
            nums1[:n] = nums2[:n]


def main():
    sol = Solution()
    # v1 = [1, 2, 3, 0, 0, 0]
    # v2 = [2, 5, 6]
    v1 = [1, 0]
    v2 = [2]
    sol.merge(v1, 1, v2, 1)
    print(v1)


if __name__ == "__main__":
    main()

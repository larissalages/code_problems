# Given a string, find the length of the longest substring without repeating characters.

# Example 1:

# Input: "abcabcbb"
# Output: 3 
# Explanation: The answer is "abc", with the length of 3. 

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        d_char_used = {}
        count = 0
        count_result = 0
        for c in s:
            if c in d_char_used:
                count = 0
                d_char_used = {}
            else:
                count += 1
                d_char_used[c] = 1
            if count > count_result:
                count_result = count
        return count_result

def main():
    res = Solution().lengthOfLongestSubstring('bbbbb')
    print(res)

if __name__ == "__main__":
    main()
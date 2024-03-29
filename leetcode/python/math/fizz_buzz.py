# Approach 1
class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        answer = []
        for i in range(1, n + 1):
            divisible_by_3 = i % 3 == 0
            divisible_by_5 = i % 5 == 0
            ans_str = ''
            if divisible_by_3:
                ans_str = "Fizz"
            if divisible_by_5:
                ans_str += "Buzz"
            if not divisible_by_3 and not divisible_by_5:
                ans_str = str(i)
            answer.append(ans_str)

        return answer

# Approach 2


class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        answer = []
        mapping = {3: 'Fizz', 5: 'Buzz'}

        for i in range(1, n + 1):
            ans_str = ''
            for key in mapping:
                if i % key == 0:
                    ans_str += mapping[key]
            if not ans_str:
                ans_str = str(i)
            answer.append(ans_str)

        return answer

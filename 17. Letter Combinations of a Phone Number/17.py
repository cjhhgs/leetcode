from typing import List
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        keyboard = {'2':'abc', '3':'def', '4':'ghi', '5':'jkl', '6':'mno', '7':'pqrs', '8':'tuv', '9':'wxyz'}
        if(len(digits)==0):
            return []
        if(len(digits)==1):
            return [c for c in keyboard[digits]]
        else:
            return [c + d for c in keyboard[digits[0]] for d in self.letterCombinations(digits[1:])]

digits = "23"
res = Solution().letterCombinations(digits)
print(res)

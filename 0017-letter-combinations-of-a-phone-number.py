# 17. Letter Combinations of a Phone Number (Medium)
# https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution:
    def letterCombinations(self, digits: str) -> list[str]:
        if not digits:
            return []
        mapping = {'2': 'abc', '3': 'def', '4': 'ghi', '5': 'jkl',
                   '6': 'mno', '7': 'pqrs', '8': 'tuv', '9': 'wxyz'}
        res = [""]
        for d in digits:
            temp = []
            for char in mapping[d]:
                for prefix in res:
                    temp.append(prefix + char)
            res = temp
        return res

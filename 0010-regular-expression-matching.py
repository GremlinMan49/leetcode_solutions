# 10. Regular Expression Matching (Hard)
# https://leetcode.com/problems/regular-expression-matching/

class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        memo = {}
        
        def dp(i, j):
            if (i, j) in memo:
                return memo[(i, j)]
            
            # If we reached the end of the pattern, we match only if we also reached the end of the string
            if j == len(p):
                return i == len(s)
            
            # Check if the current characters match
            first_match = i < len(s) and (p[j] == s[i] or p[j] == '.')
            
            # If the next character in the pattern is a '*'
            if j + 1 < len(p) and p[j + 1] == '*':
                # Option 1: Skip the '*' pair (match zero occurrences)
                # Option 2: If first match is true, consume one character in 's' and stay on the same pattern index
                ans = dp(i, j + 2) or (first_match and dp(i + 1, j))
            else:
                # Regular match: consume one character from both string and pattern
                ans = first_match and dp(i + 1, j + 1)
                
            memo[(i, j)] = ans
            return ans

        return dp(0, 0)

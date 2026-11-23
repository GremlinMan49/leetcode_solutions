# 7. Reverse Integer (Medium)
# https://leetcode.com/problems/reverse-integer/

class Solution:
    def reverse(self, x: int) -> int:
        y = str(x)
        rev = y[::-1]
        if x < 0:
            negrev = rev[:-1]
            fnr = f"-{negrev}"
            output = int(fnr)
            if output < -2**31:
                return 0
        else:
            output = int(rev)
        if output > (2**31 - 1):
            return 0
        return output
        
        

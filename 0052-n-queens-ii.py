# 52. N-Queens II (Hard)
# https://leetcode.com/problems/n-queens-ii/

class Solution:

  def totalNQueens(self, n: int) -> int:
    col = set()
    pos_diag = set()
    neg_diag = set()
    count = 0

    def backtrack(r):
      nonlocal count
      if r == n:
        count += 1
        return
      for c in range(n):
        if c in col or (r + c) in pos_diag or (r - c) in neg_diag:
          continue
        col.add(c)
        pos_diag.add(r + c)
        neg_diag.add(r - c)
        backtrack(r + 1)
        col.remove(c)
        pos_diag.remove(r + c)
        neg_diag.remove(r - c)

    backtrack(0)
    return count

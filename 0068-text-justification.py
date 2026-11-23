# 68. Text Justification (Hard)
# https://leetcode.com/problems/text-justification/

class Solution:

  def fullJustify(self, words: list[str], maxWidth: int) -> list[str]:
    res = []
    curr = []
    num_of_letters = 0
    for w in words:
      if num_of_letters + len(w) + len(curr) > maxWidth:
        if len(curr) == 1:
          res.append(curr[0] + " " * (maxWidth - len(curr[0])))
        else:
          num_spaces = maxWidth - num_of_letters
          space_slots = len(curr) - 1
          spaces = num_spaces // space_slots
          extra = num_spaces % space_slots
          line = ""
          for i in range(space_slots):
            line += curr[i] + " " * (spaces + (1 if i < extra else 0))
          line += curr[-1]
          res.append(line)
        curr, num_of_letters = [], 0
      curr.append(w)
      num_of_letters += len(w)
    last_line = " ".join(curr)
    res.append(last_line + " " * (maxWidth - len(last_line)))
    return res

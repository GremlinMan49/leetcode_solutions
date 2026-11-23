# 30. Substring with Concatenation of All Words (Hard)
# https://leetcode.com/problems/substring-with-concatenation-of-all-words/

from collections import Counter


class Solution:

  def findSubstring(self, s: str, words: list[str]) -> list[int]:
    if not s or not words:
      return []
    word_len = len(words[0])
    num_words = len(words)
    total_len = word_len * num_words
    word_count = Counter(words)
    result = []
    for i in range(word_len):
      left = i
      right = i
      cur_count = Counter()
      count = 0
      while right + word_len <= len(s):
        word = s[right : right + word_len]
        right += word_len
        if word in word_count:
          cur_count[word] += 1
          count += 1
          while cur_count[word] > word_count[word]:
            left_word = s[left : left + word_len]
            cur_count[left_word] -= 1
            count -= 1
            left += word_len
          if count == num_words:
            result.append(left)
        else:
          cur_count.clear()
          count = 0
          left = right
    return result

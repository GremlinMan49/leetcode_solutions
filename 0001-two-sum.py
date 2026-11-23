# 1. Two Sum (Easy)
# https://leetcode.com/problems/two-sum/

class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        output = [0,0]
        solution = 0
        for x in range(len(nums)):
            for y in range(len(nums)):
                if x == y:
                    continue
                if nums[x] + nums[y] == target: 
                    output[0] = x
                    output[1] = y
                    break
        return output

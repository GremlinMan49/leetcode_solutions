# 16. 3Sum Closest (Medium)
# https://leetcode.com/problems/3sum-closest/

class Solution:
    def threeSumClosest(self, nums: list[int], target: int) -> int:
        nums.sort()
        closest = sum(nums[:3])
        for i in range(len(nums) - 2):
            l, r = i + 1, len(nums) - 1
            while l < r:
                s = nums[i] + nums[l] + nums[r]
                if abs(s - target) < abs(closest - target):
                    closest = s
                if s < target:
                    l += 1
                elif s > target:
                    r -= 1
                else:
                    return target
        return closest

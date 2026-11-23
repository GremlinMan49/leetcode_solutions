# 1606. Find Servers That Handled Most Number of Requests (Hard)
# https://leetcode.com/problems/find-servers-that-handled-most-number-of-requests/

import heapq
from typing import List

class Solution:
    def busiestServers(self, k: int, arrival: List[int], load: List[int]) -> List[int]:
        count = [0] * k
        available = list(range(k))
        busy = []                           
        for i, start in enumerate(arrival):
            while busy and busy[0][0] <= start:
                _, s = heapq.heappop(busy)
                heapq.heappush(available, i + (s - i) % k)

            if available:                    
                s = heapq.heappop(available) % k
                count[s] += 1
                heapq.heappush(busy, (start + load[i], s))

        best = max(count)
        return [s for s in range(k) if count[s] == best]

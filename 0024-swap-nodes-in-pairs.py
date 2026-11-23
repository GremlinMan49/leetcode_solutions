# 24. Swap Nodes in Pairs (Medium)
# https://leetcode.com/problems/swap-nodes-in-pairs/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head):
        dummy = ListNode(0, head)
        prev, curr = dummy, head
        while curr and curr.next:
            nxt = curr.next
            curr.next = nxt.next
            nxt.next = curr
            prev.next = nxt
            prev = curr
            curr = curr.next
        return dummy.next

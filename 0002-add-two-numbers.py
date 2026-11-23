# 2. Add Two Numbers (Medium)
# https://leetcode.com/problems/add-two-numbers/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode | None, l2: ListNode | None) -> ListNode | None:
        def to_number(node):
            total, place = 0, 1
            while node:
                total += node.val * place      
                place *= 10
                node = node.next
            return total

        fsum = to_number(l1) + to_number(l2)

        dummy = ListNode()
        tail = dummy
        for digit in reversed(str(fsum)):     
            tail.next = ListNode(int(digit))
            tail = tail.next
        return dummy.next
        for x in range(lenf):
            fdig = fsum % power(x)
            output.append(fdig)
        return output


            

        

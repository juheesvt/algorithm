# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

from pprint import pprint 

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        node, reverse = None, None
        while head:
            reverse = ListNode(head.val, node)
            head = head.next
            node = reverse
        return reverse
        
        
        
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        
        l = self.lenOfList(head)
        c = l - n
        h = head
        if(c==0):
            head = head.next
            return head
        while(c!=1):
            h = h.next
            c-=1
        h.next=h.next.next

        return head
    def lenOfList(self,head):
        count=0
        h = head
        while(h!=None):
            h=h.next
            count+=1
        return count
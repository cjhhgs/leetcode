# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        
        if list1==None:
            return list2
        if list2==None:
            return list1

        w = list1

        if(list1.val<list2.val):
            head=list1
            list1=list1.next
        else:
            head = list2
            list2=list2.next
        
        w=head
        while(list1!=None and list2!=None):
            if list1.val<list2.val:
                head.next=list1
                list1=list1.next
                head = head.next
            else:
                head.next=list2
                list2=list2.next
                head = head.next

        if(list1==None):
            head.next=list2
        else:
            head.next=list1
        
        return w


            



from typing import List
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        list=[]
        for l in lists:
            while(l!=None):
                list.append(l.val)
                l=l.next
        

        head=ListNode()
        p=head
        heap=MinHeap()
        heap.make(list)
        while(heap.size>0):
            i=heap.pop()
            item=ListNode(i)
            p.next=item
            p=item
        if head.next!=None:
            return head.next
        else:
            return None

class MinHeap:
    def __init__(self) -> None:
        self.size=0
        self.heap=[]

    def make(self,list):
        
        for i in list:
            self.add(i)
        
    def add(self,item):
        self.heap.append(item)
        self.size+=1
        self.shiftup()
    
    def shiftup(self):
        index = self.size-1
        while(index>0):
            i = int((index-1)/2)
            if(self.heap[i]>self.heap[index]):
                temp=self.heap[i]
                self.heap[i]=self.heap[index]
                self.heap[index]=temp
                index=i
            else:
                break
    
    def shiftdown(self):
        if(self.size<2):
            return
        index=0
        while(index<=int((self.size-2)/2)):
            if(self.heap[index*2+1]>self.heap[index*2+2]):
                i=index*2+2
            else:
                i=index*2+1

            if(self.heap[i]<self.heap[index]):
                temp=self.heap[i]
                self.heap[i]=self.heap[index]
                self.heap[index]=temp
                index=i
            else:
                break

    def pop(self):
        if(self.size==0):
            return None
        top = self.heap[0]
        self.heap[0]=self.heap[self.size-1]
        self.size-=1
        self.shiftdown()
        return top
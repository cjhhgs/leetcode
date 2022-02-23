from tkinter import S
from typing import List
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        
        l = len(nums)
        if l<3:
            return []

        nums = nums.sort()
        index=0
        res = []
        for i in range(0,l-2):
            for j in range(i+1,l-1):
                for k in range(j+1,l):
                    t = nums[i]+nums[j]+nums[k]
                    if(t==0):
                        temp = [nums[i],nums[j],nums[k]]
                        if(temp!=res[index]):
                            res.append(t)
                            index+=1
        return res
nums = [-1,0,1,2,-1,-4]
res = Solution().threeSum(nums)
print(res)
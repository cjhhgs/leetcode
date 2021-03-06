
from typing import List
class Solution:
    
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        
        l = len(nums)
        if l<3:
            return []

        nums.sort()
        
        res = []
        for i in range(0,l-2):
            if (i>0 and nums[i]==nums[i-1]):
                continue
            j=i+1
            k=len(nums)-1
            while(j<k):
                if(j>i+1 and nums[j]==nums[j-1]):
                    j+=1
                    continue
                if(k<len(nums)-1 and nums[k]==nums[k+1]):
                    k-=1
                    continue

                t = nums[i]+nums[j]+nums[k]
                if(t==0):
                    res.append([nums[i],nums[j],nums[k]])
                    j+=1
                    k-=1
                elif(t>0):
                    k-=1
                else:
                    j+=1
                            
        return res
    
nums = [-4,-1,-1,0,1,2]
res = Solution().threeSum(nums)
print(res)
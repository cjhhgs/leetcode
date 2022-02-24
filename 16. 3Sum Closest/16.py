from typing import List
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        l = len(nums)
        if l<3:
            return []

        nums.sort()
        res = nums[0]+nums[1]+nums[2]
        
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

                t = nums[i]+nums[j]+nums[k]-target
                if(abs(t)<abs(res-target)):
                    res = t+target
                if(t==0):
                    return target
                    j+=1
                    k-=1
                elif(t>0):
                    k-=1
                else:
                    j+=1
                            
        return res

nums = [-1,2,1,-4]
target = 1
res = Solution().threeSumClosest(nums,target)
print(res)
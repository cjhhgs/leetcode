from typing import List
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        if(len(nums)<4):
            return []
        
        res = []
        nums.sort()
        n = len(nums)
        for i in range(0,n-3):
            if (i>0 and nums[i]==nums[i-1]):
                continue
            for j in range(i+1,n-2):
                if (j>i+1 and nums[j]==nums[j-1]):
                    continue
                k=j+1
                l=n-1
                while(k<l):
                    if(k>j+1 and nums[k]==nums[k-1]):
                        k+=1
                        continue
                    if(l<n-1 and nums[l]==nums[l+1]):
                        l-=1
                        continue
                    t = nums[i]+nums[j]+nums[k]+nums[l]-target
                    if(t==0):
                        res.append([nums[i],nums[j],nums[k],nums[l]])
                        k+=1
                        l-=1
                    elif(t>0):
                        l-=1
                    else:
                        k+=1
        return res

nums = [1,0,-1,0,-2,2]
target = 0
res = Solution().fourSum(nums,target)
print(res)
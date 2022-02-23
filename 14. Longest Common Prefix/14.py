from textwrap import indent
from typing import List

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if(len(strs)==1):
            return strs[0]
        k=0
        flag =1
        minl = len(strs[0])
        maxl=0
        for i in strs:
            tl = len(i)
            if tl<minl:
                minl=tl

        while(k<minl):
            t = strs[0][k]
            for i in strs:
                if(i[k]!=t):
                    flag=0
            if(flag==0):
                break
            k+=1
            maxl+=1

        if maxl==0:
            return ""
        res = strs[0][0:maxl]
        return res
strs = ["flower","flow","flight"]
res = Solution().longestCommonPrefix(strs)
print(res)
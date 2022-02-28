class Solution:
    
    def isMatch(self, s: str, p: str) -> bool:
        l1 = len(s)
        l2 = len(p)
        dpmap = [[0 for i in range(l2+1)] for j in range(l1+1)]
        
        def dp(i,j):
            if(dpmap[i][j]!=0):
                if(dpmap[i][j]==1):
                    return True
                return False
            else:
                if(j==len(p)):
                    t = i==len(s)       
                else:
                
                    first_match = (i<len(s)) and (s[i]==p[j] or p[j]=='.')

                    if(j<len(p)-1 and p[j+1]=='*'):
                        t = dp(i,j+2) or (first_match and dp(i+1,j))
                    else:
                        t=first_match and dp(i+1,j+1)

                if(t==True):
                    dpmap[i][j]=1
                else:
                    dpmap[i][j]=2
                return t

        return dp(0,0)

s = "mississippi"
p = "mis*is*ip*."

res = Solution().isMatch(s,p)
print(res)
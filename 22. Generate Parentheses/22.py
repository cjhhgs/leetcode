from typing import List
class Solution:
    res=[]
    def generateParenthesis(self, n: int) -> List[str]:
        self.res=[]
        s=str("")
        self.func(0,0,n,s)
        return self.res
    
    def func(self,num1,num2,n,s):
        if(num2==n):
            self.res.append(s)
            return
        else:
            if(num1==num2):
                
                self.func(num1+1,num2,n,s+'(')
               
            else:
                if(num1<n):
                    self.func(num1+1,num2,n,s+'(')
                
                self.func(num1,num2+1,n,s+')')
                
            return

res = Solution().generateParenthesis(3)
print(res)
class Solution:
    def isValid(self, s: str) -> bool:
        r = []
        for i in s:
            if (i == '(' or i=='[' or i=='{'):
                r.append(i)
            else:
                if(i==')'):
                    if(len(r)==0 or r[-1]!='('):
                        return False
                    else:
                        r.pop()
                if(i==']'):
                    if(len(r)==0 or r[-1]!='['):
                        return False
                    else:
                        r.pop()
                if(i=='}'):
                    if(len(r)==0 or r[-1]!='{'):
                        return False
                    else:
                        r.pop()
        if len(r)!=0:
            return False
        return True
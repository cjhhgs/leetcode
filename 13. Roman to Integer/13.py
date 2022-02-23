class Solution:
    def romanToInt(self, s: str) -> int:
        res=0
        map = {'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000}
        l = len(s)
        i=0
        while(i<l):
            if(i+1<l):
                if(map[s[i]]<map[s[i+1]]):
                    res=res-map[s[i]]+map[s[i+1]]
                    i=i+2
                else:
                    res=res+map[s[i]]
                    i=i+1
            else:
                res=res+map[s[i]]
                i=i+1
        return res

print(Solution().romanToInt("LVIII"))
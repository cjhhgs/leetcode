class Solution:
    def intToRoman(self, num: int) -> str:
        res=''
        map = {'M':1000,'CM':900,'D':500,'CD':400,'C':100,'XC':90,'L':50,'XL':40,'X':10,'IX':9,'V':5,'IV':4,'I':1}
        for i in map:
            if(num>=map[i]):
                j = num/map[i]
                j=int(j)
                num = num%map[i]
                res = res+j*i
        return res
t = Solution()
print(t.intToRoman(1900))

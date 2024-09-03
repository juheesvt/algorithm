class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        cnt = 0
        last = 0
        for i in range(len(s)):
            if s[i] in t:
                cnt += 1
                last = t.index(s[i])
                t = t[last + 1:]
        
        if cnt == len(s):
            return True
        return False


        
class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        if str1 + str2 != str2 + str1:
            return ""

        # gcd algorithm
        a, b = max(len(str1), len(str2)), min(len(str1), len(str2))
        n = a % b
        while n:
            a = b
            b = n
            n = a % b

        return str1[:b]
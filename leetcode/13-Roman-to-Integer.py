class Solution:
    def romanToInt(self, s: str) -> int:

        roman2int = {
            'I': 1,
            'V': 5,
            'X': 10,
            'L': 50,
            'C': 100,
            'D': 500,
            'M': 1000
        }

        answer, idx = 0, 0
        while idx < len(s):
            if s[idx] == 'I' and idx + 1 < len(s):
                if s[idx + 1] == 'V':
                    answer += 4
                    idx += 2
                elif s[idx + 1] == 'X':
                    answer += 9
                    idx += 2
                else:
                    answer += roman2int[s[idx]]
                    idx += 1
            elif s[idx] == 'X' and idx + 1 < len(s):
                if s[idx + 1] == 'L':
                    answer += 40
                    idx += 2
                elif s[idx + 1] == 'C':
                    answer += 90
                    idx += 2
                else:
                    answer += roman2int[s[idx]]
                    idx += 1
            elif s[idx] == 'C' and idx + 1 < len(s):
                if s[idx + 1] == 'D':
                    answer += 400
                    idx += 2
                elif s[idx + 1] == 'M':
                    answer += 900
                    idx += 2
                else:
                    answer += roman2int[s[idx]]
                    idx += 1
            else:
                answer += roman2int[s[idx]]
                idx += 1
            
        return answer
        
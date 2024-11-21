class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        for i in range(len(s)):
            if s[i] == ']':
                if stack and stack[-1] == '[':
                    del stack[-1]
                else:
                    return False
            elif stack and s[i] == ')':
                if stack[-1] == '(':
                    del stack[-1]
                else:
                    return False
            elif stack and s[i] == '}':
                if stack[-1] == '{':
                    del stack[-1]
                else:
                    return False
            else:
                stack.append(s[i])
            
        if not stack:
            return True
        return False
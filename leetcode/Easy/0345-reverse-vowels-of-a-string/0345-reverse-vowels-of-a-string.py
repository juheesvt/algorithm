class Solution:
    def reverseVowels(self, s: str) -> str:
        stack = []
        answer = []
        vowels = "aAeEiIoOuU"
        for i in range(len(s)):
            if s[i] in vowels:
                stack.append(s[i])
                answer.append("*")
            else:
                answer.append(s[i])
        
        for i in range(len(s)):
            if answer[i] == "*":
                answer[i] = stack[-1]
                del stack[-1]

        return "".join(answer)
        
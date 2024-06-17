class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        answer = ""
        last_idx = min(len(word1), len(word2))
        for i in range(last_idx):
            answer += word1[i] + word2[i]

        answer += word2[len(word1):] if len(word1) < len(word2) else word1[len(word2):]
        return answer
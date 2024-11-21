class Solution:
    def countBits(self, n: int) -> List[int]:
        if n == 0:
            return [0]
        
        answer = [0, 1]
        for i in range(2, n + 1):
            answer.append(answer[floor(i / 2)] if i % 2 == 0 else answer[floor(i / 2)] + 1)
        return answer
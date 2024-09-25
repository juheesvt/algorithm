class Solution:
    def countBits(self, n: int) -> List[int]:
        answer = [0]
        for i in range(1, n + 1):
            answer.append(sum(map(int, list(format(i, 'b')))))
        return answer
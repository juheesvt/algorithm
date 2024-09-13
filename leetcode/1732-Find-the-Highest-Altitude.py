class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        current, max_num = 0, 0
        for _gain in gain:
            current += _gain
            if max_num < current:
                max_num = current

        return max_num
        
from collections import Counter

class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """

        zero = Counter(nums)[0]
        
        while 0 in nums:
            nums.remove(0)

        for i in range(zero):
            nums.append(0)

        return nums
        
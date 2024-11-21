import numpy as np

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:

        answer = [1 for i in range(len(nums))]
        l, r = 1, 1

        for i in range(len(nums)):
            answer[i] *= l
            l *= nums[i]

        for i in range(len(nums) - 1, -1, -1):
            answer[i] *= r
            r *= nums[i]

        return answer
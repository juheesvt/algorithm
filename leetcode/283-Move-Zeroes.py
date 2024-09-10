class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        \\\
        Do not return anything, modify nums in-place instead.
        \\\

        cnt = 0
        while 0 in nums:
            nums.remove(0)
            cnt += 1
        
        for i in range(cnt):
            nums.append(0)
        
class Solution:
    def findDifference(self, nums1: List[int], nums2: List[int]) -> List[List[int]]:
        nums1_delete = []
        for num in nums1:
            if num in nums2:
                nums1_delete.append(num)

        nums2_delete = []
        for num in nums2:
            if num in nums1:
                nums2_delete.append(num)


        for num in nums1_delete:
            while num in nums1:
                nums1.remove(num)


        for num in nums2_delete:
            while num in nums2:
                nums2.remove(num)

        return [list(set(nums1)), list(set(nums2))]
        
        
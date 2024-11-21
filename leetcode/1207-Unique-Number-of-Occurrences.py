class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        count_dict = {}
        for num in arr:
            if num not in count_dict:
                count_dict[num] = 1
            else:
                count_dict[num] += 1

        if len(count_dict.values()) == len(list(set(count_dict.values()))):
            return True
        return False
        
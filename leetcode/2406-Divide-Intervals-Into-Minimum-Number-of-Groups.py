class Solution:
    def minGroups(self, intervals: List[List[int]]) -> int:
        start_times = sorted(i[0] for i in intervals)
        end_times = sorted(i[1] for i in intervals)
        end, group_cnt = 0, 0

        for start in start_times:
            if start > end_times[end]:
                end += 1
            else:
                group_cnt += 1
        
        return group_cnt
                
            
            

        
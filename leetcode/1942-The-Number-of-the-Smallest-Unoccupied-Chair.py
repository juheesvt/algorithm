class Solution:
    def smallestChair(self, times: List[List[int]], targetFriend: int) -> int:
        
        friends_num = len(times)
        ordered_friends = sorted(range(len(times)), key=lambda x: times[x][0])
        empty_chairs, occupied_chairs = list(range(len(times))), []

        for i in ordered_friends:
            arrive, leave = times[i]

            while occupied_chairs and occupied_chairs[0][0] <= arrive:
                heappush(empty_chairs, heappop(occupied_chairs)[1])
            min_chair = heappop(empty_chairs)

            if i == targetFriend:
                return min_chair
            
            heappush(occupied_chairs, (leave, min_chair))
        
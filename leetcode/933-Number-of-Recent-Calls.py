class RecentCounter:

    def __init__(self):
        self.t_arr = []
        self.start = 0
        

    def ping(self, t: int) -> int:
        self.t_arr.append(t)
        while self.t_arr[self.start] < t - 3000:
            self.start += 1
        return len(self.t_arr) - self.start
        


# Your RecentCounter object will be instantiated and called as such:
# obj = RecentCounter()
# param_1 = obj.ping(t)